#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e6 + 10;
const int inf = 100;

int alp[50][30];
string s[30];
int dp[42][(1<<20) + 10];

int cost(char x){
	if (x == 'a')
		return 1;
	if (x == 'b')
		return -1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < n; j++)
			s[i] += '@';
	}
	for (int i = 0; i <= 2*n-2; i++){
		for (int c = 0; c < 26; c++){
			for (int j = 0; j <= min(i, n-1); j++){
				int k = i - j;
				if (s[j][k] == (char)(c + 'a'))
					alp[i][c] |= (1 << j);
			}
		}
	}
	for (int i = 2*n-3; i >= 0; i--){
		int len = min(i+1, n);
		for (int mask = 0; mask < (1 << len); mask++){
			if (i & 1)
				dp[i][mask] = -inf;
			else
				dp[i][mask] = +inf;
			int nex = (mask | (mask << 1));
			for (int c = 0; c < 26; c++){
				int then = (alp[i+1][c] & nex);
				if (then == 0)
					continue;
				if (i & 1)
					dp[i][mask] = max(dp[i][mask], dp[i+1][then] + cost((char)(c + 'a')));
				else
					dp[i][mask] = min(dp[i][mask], dp[i+1][then] + cost((char)(c + 'a')));
			}
		}
	}
	int x = dp[0][1] + cost(s[0][0]);
	if (x == 0)
		cout << "DRAW\n";
	if (x < 0)
		cout << "SECOND\n";
	if (x > 0)
		cout << "FIRST\n";
}