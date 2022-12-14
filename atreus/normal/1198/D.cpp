#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
const int maxm = 5e5 + 10;

int dp[52][52][52][52];
string s[55];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = " " + s[i];
	}
	for (int lenx = 1; lenx <= n; lenx++){
		for (int leny = 1; leny <= n; leny++){
			for (int x1 = 1; x1 + lenx - 1 <= n; x1++){
				for (int y1 = 1; y1 + leny - 1 <= n; y1++){
					if (lenx == 1 and leny == 1){
						dp[1][1][x1][y1] = (s[x1][y1] == '#');
						continue;
					}
					int x2 = x1 + lenx - 1;
					int y2 = y1 + leny - 1;
					dp[lenx][leny][x1][y1] = max(lenx, leny);
					if (lenx >= leny){
						for (int midx = x1; midx < x2; midx++){
							int L1 = midx - x1 + 1;
							int L2 = x2 - midx;
							dp[lenx][leny][x1][y1] = min(dp[lenx][leny][x1][y1], dp[L1][leny][x1][y1] + dp[L2][leny][midx+1][y1]);
						}
					}
					else{
						for (int midy = y1; midy < y2; midy++){
							int L1 = midy - y1 + 1;
							int L2 = y2 - midy;
							dp[lenx][leny][x1][y1] = min(dp[lenx][leny][x1][y1], dp[lenx][L1][x1][y1] + dp[lenx][L2][x1][midy+1]);
						}
					}
				}
			}
		}
	}
	cout << dp[n][n][1][1] << endl;
}