#include <iostream>
#include <algorithm>
using namespace std;

int nbLigs, nbCols;
string terrain[100];
string prog;

int dirs[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

bool estValide(int lig, int col) {
	if(lig < 0 || col < 0 || lig >= nbLigs || col >= nbCols)
		return false;
	if(terrain[lig][col] == '#')
		return false;
	return true;
}

int main() {
	cin >> nbLigs >> nbCols;
	
	int sLig, sCol;
	for(int iLig = 0;iLig < nbLigs;iLig++) {
		cin >> terrain[iLig];
		for(int iCol = 0;iCol < nbCols;iCol++) {
			if(terrain[iLig][iCol] == 'S') {
				sLig = iLig;
				sCol = iCol;
			}
		}
	}
	
	cin >> prog;
	
	int count = 0;
	vector<int> perm = {1, 2, 3, 4};
	do {
		int lig = sLig, col = sCol;
		for(char ins : prog) {
			lig += dirs[perm[ins-'0'] - 1][0];
			col += dirs[perm[ins-'0'] - 1][1];
			if(!estValide(lig, col)) {
				break;
			}
			if(terrain[lig][col] == 'E') {
				count++;
				break;
			}
		}
	} while(next_permutation(perm.begin(), perm.end()));
	
	cout << count << endl;
	return 0;
}