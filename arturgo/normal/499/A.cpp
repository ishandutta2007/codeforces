#include <iostream>
using namespace std;

int main() {
	int nbMoments, skip;
	cin >> nbMoments >> skip;
	
	int nbMinutes = 0;
	
	int pos = 1;
	for(int iMoment = 0;iMoment < nbMoments;iMoment++) {
		int deb, fin;
		cin >> deb >> fin;
		
		while(pos + skip <= deb)
			pos += skip;
		nbMinutes += deb - pos;
		
		nbMinutes += fin - deb + 1;
		pos = fin + 1;
	}
	
	cout << nbMinutes << endl;
}