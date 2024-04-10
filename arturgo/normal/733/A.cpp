#include <iostream>
using namespace std;

bool estVoyelle(char lettre) {
	if(lettre == 'A' || lettre == 'E' || lettre == 'I')
		return true;
	if(lettre == 'O' || lettre == 'U' || lettre == 'Y')
		return true;
	return false;
}

int main() {
	string chaine;
	cin >> chaine;
	
	int curSaut = 1, maxSaut = 0;
	for(char car : chaine) {
		if(estVoyelle(car)) {
			maxSaut = max(maxSaut, curSaut);
			curSaut = 0;
		}
		curSaut++;
	}
	maxSaut = max(maxSaut, curSaut);
	
	cout << maxSaut << endl;
	return 0;
}