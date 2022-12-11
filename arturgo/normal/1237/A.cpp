#include <iostream>
using namespace std;

int main() {
	int nbGens;
	cin >> nbGens;

	int ajout = 1;
	for(int iGens = 0;iGens < nbGens;iGens++) {
		int score;
		cin >> score;

		if(score % 2 == 0) {
			cout << score / 2 << endl;
		}
		else {
			cout << (score + ajout) / 2 << endl;
			ajout = -ajout;
		}
	}

	return 0;
}