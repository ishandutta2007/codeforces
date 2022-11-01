# include <bits/stdc++.h>

using namespace std;

const long md = 1e9+7;
const int xn = 2e3+10;
int dp[xn][xn];
vector <int> p[xn];

int main(){
	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=i; j++){
			if (i%j == 0) p[i].push_back(j);
		}
	}
	long long s = 0;
	for (int i=1; i<=n; i++) dp[i][1] = 1;
	for (int j=2; j<=k; j++){
		for (int i=1; i<=n; i++){
			s = 0;
			//cout << p[i].size() << endl;
			for (int l=0; l<p[i].size(); l++) s += dp[p[i][l]][j-1], s %= md;
			dp[i][j] = s;
		}
	}
	s = 0;
	for (int i=1; i<=n; i++) s += dp[i][k], s %= md;
	cout << s;
}