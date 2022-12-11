#include <iostream>
using namespace std;

int main() {
	string chaine;
	cin >> chaine;
	
	int nbDiffs = 0;
	for(int iCar = 0;iCar < (int)chaine.size() / 2;iCar++) {
		if(chaine[iCar] != chaine[chaine.size() - 1 - iCar])
			nbDiffs++;
	}
	
	if(nbDiffs >= 2 || (chaine.size() % 2 == 0 && nbDiffs == 0))
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}