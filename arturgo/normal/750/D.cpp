#include <iostream>

using namespace std;

int nbNiveaux;
int tailles[40];
bool estPasse[4][40][400][400];
bool estCol[400][400];
int nbCols = 0;

int dirs[8][2] = {
	{1, 0},
	{1, 1},
	{0, 1},
	{-1, 1},
	{-1, 0},
	{-1, -1},
	{0, -1},
	{1, -1}
};

void passe(int x, int y, int d, int dir) {
	if(d == nbNiveaux)
		return;
	
	if(estPasse[dir / 2][d][x][y]) {
		return;
	}
	
	estPasse[dir / 2][d][x][y] = true;
	
	int nx = x, ny = y;
	
	for(int iF = 0;iF < tailles[d];iF++) {
		nx += dirs[dir][0];
		ny += dirs[dir][1];
		
		if(!estCol[nx][ny]) {
			estCol[nx][ny] = true;
			nbCols++;
		}
	}
	
	passe(nx, ny, d + 1, (dir + 1) % 8);
	passe(nx, ny, d + 1, (dir + 7) % 8);
}

int main() {
   	cin >> nbNiveaux;
   	
   	for(int iNiveau = 0;iNiveau < nbNiveaux;iNiveau++) {
   		cin >> tailles[iNiveau];
   	}
   	
   	passe(200, 200, 0, 0);
   	
   	cout << nbCols << endl;
    return 0;
}