#include <iostream>
#include <cstdio>
using namespace std;

const int INFINI = 50;

string terrain[50];

int dp[50][50][50][50];

signed main() {
	ios_base::sync_with_stdio(false);
	int cote;
	cin >> cote;

	for(int i = 0;i < cote;i++)
		cin >> terrain[i];

	for(int ligA = cote - 1;ligA >= 0;ligA--) {
		for(int colA = cote - 1;colA >= 0;colA--) {
			for(int ligB = ligA;ligB < cote;ligB++) {
				for(int colB = colA;colB < cote;colB++) {
					if(ligA == ligB && colA == colB) {
						dp[ligA][colA][ligB][colB] = (terrain[ligA][colA] == '#');
						continue;
					}
					
					int cur = INFINI;

					for(int lig = ligA + 1;lig <= ligB;lig++) {
						cur = min(cur, dp[ligA][colA][lig - 1][colB] + dp[lig][colA][ligB][colB]);
					}

					for(int col = colA + 1;col <= colB;col++) {
						cur = min(cur, dp[ligA][colA][ligB][col - 1] + dp[ligA][col][ligB][colB]);
					}

					dp[ligA][colA][ligB][colB] = min(cur, max(ligB - ligA + 1, colB - colA + 1));
				}
			}
		}
	}

	cout << dp[0][0][cote - 1][cote - 1] << endl;

	return 0;
}