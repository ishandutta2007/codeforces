#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nbChaines;
vector<string> chaines;

string rot(string chaine) {
	rotate(chaine.begin(), chaine.begin() + 1, chaine.end());
	return chaine;
}

int nbFlips(string a, string b) {
	for(int iFois = 0;iFois < 100;iFois++) {
		if(a == b)
			return iFois;
		b = rot(b);
	}
	return 1000 * 1000 * 1000;
}

int moves() {
	int total = 0;
	for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
		if(nbFlips(chaines[0], chaines[iChaine]) == 1000 * 1000 * 1000)
			return 1000 * 1000 * 1000;
		total += nbFlips(chaines[0], chaines[iChaine]);
	}
	return total;
}

int main() {
	
	cin >> nbChaines;
	
	for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
		string chaine;
		cin >> chaine;
		chaines.push_back(chaine);
	}
	
	int minMoves = 1000 * 1000 * 1000;
	for(int iCar = 0;iCar < chaines[0].size();iCar++) {
		minMoves = min(minMoves, moves() + iCar);
		chaines[0] = rot(chaines[0]);
	}
	
	if(minMoves == 1000 * 1000 * 1000)
		cout << -1 << endl;
	else
		cout << minMoves << endl;
	return 0;
}