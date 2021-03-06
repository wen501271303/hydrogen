/*
 * Hydrogen
 * Copyright(c) 2002-2008 by Alex >Comix< Cominu [comix@users.sourceforge.net]
 *
 * http://www.hydrogen-music.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <core/Version.h>
#include "DonationDialog.h"
#include "Skin.h"

#include <core/Globals.h>


DonationDialog::DonationDialog(QWidget* parent)
 : QDialog( parent )
{
	setupUi( this );

	setWindowTitle( tr( "Donations" ) );
}

DonationDialog::~DonationDialog()
{
}


void DonationDialog::on_randomizeBtn_clicked()
{
	int r = rand() % 2;
	
	if( r == 0 ) {
		radioButton->setChecked(true);
	} else {
		radioButton_2->setChecked(true);
	}
}

void DonationDialog::on_donateBtn_clicked()
{
	if(radioButton->isChecked()) {
		QDesktopServices::openUrl(QUrl::fromEncoded("https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=sebastian%2emoors%40gmail%2ecom&lc=DE&item_name=Hydrogen%20donation&no_note=0&currency_code=EUR&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHostedGuest"));
	} else {
		QDesktopServices::openUrl(QUrl::fromEncoded("https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=m%2ewolkstein%40gmx%2ede&lc=DE&item_name=Hydrogen%20donation&no_note=0&currency_code=EUR&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHostedGuest"));
	}
	accept();
}
