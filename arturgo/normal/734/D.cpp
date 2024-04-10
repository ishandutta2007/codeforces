#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INFINI = 2000 * 1000 * 1000;

char mins[10] = "IIIIIIII";
vector<int> dists(8, INFINI);

int main() {
	int nbPieces;
	cin >> nbPieces;
	
	int rX, rY;
	cin >> rX >> rY;
	
	for(int iPiece = 0;iPiece < nbPieces;iPiece++) {
		char type;
		int pX, pY;
		cin >> type >> pX >> pY;
		
		int dX = pX - rX;
		int dY = pY - rY;
		
		if(dX == 0) {
			if(dY > 0 && dY <= dists[0]) {
				dists[0] = dY;
				mins[0] = type;
			}
			if(dY < 0 && -dY <= dists[1]) {
				dists[1] = -dY;
				mins[1] = type;
			}
		}
		if(dY == 0) {
			if(dX > 0 && dX <= dists[2]) {
				dists[2] = dX;
				mins[2] = type;
			}
			if(dX < 0 && -dX <= dists[3]) {
				dists[3] = -dX;
				mins[3] = type;
			}
		}
		if(dX == dY) {
			if(dY > 0 && dY <= dists[4]) {
				dists[4] = dY;
				mins[4] = type;
			}
			if(dY < 0 && -dY <= dists[5]) {
				dists[5] = -dY;
				mins[5] = type;
			}
		}
		if(dY == -dX) {
			if(dX > 0 && dX <= dists[6]) {
				dists[6] = dX;
				mins[6] = type;
			}
			if(dX < 0 && -dX <= dists[7]) {
				dists[7] = -dX;
				mins[7] = type;
			}
		}
	}
	
	for(int iDir = 0;iDir < 4;iDir++) {
		if(mins[iDir] == 'R' || mins[iDir] == 'Q') {
			cout << "YES" << endl;
			return 0;
		}
	}
	
	for(int iDir = 4;iDir < 8;iDir++) {
		if(mins[iDir] == 'B' || mins[iDir] == 'Q') {
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
	return 0;
}