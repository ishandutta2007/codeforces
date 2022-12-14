#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[] = {119, 36, 93, 109, 46, 107, 123, 37, 127, 111};
int dp[140][10];
bool p[2010][2010];
int b[2010];

int main(){
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < 10; i++){
		for (int mask = 0; mask < 128; mask++){
			if ((mask & a[i]) == mask){
				int diff = __builtin_popcount(mask^a[i]);
				dp[mask][diff] = i;
			}
		}
	}
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		int m = 0;
		for (int j = 0; j < 7; j++)
			if (s[j] == '1')
				m += (1 << j);
		b[i] = m;
	}
	p[n][0] = 1;
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j <= k; j++)
			for (int x = 0; x <= min(j,7); x++)
				if (dp[b[i]][x] != -1)
					p[i][j] |= p[i+1][j-x];
	if (p[0][k] == false)
		return cout << -1 << endl, 0;
	int i = 0, j = k;
	while (i < n){
		int me = -1;
		for (int x = 0; x <= min(j,7); x++)
			if (dp[b[i]][x] != -1 and p[i+1][j-x] == 1)
				if (me == -1 or dp[b[i]][x] > dp[b[i]][me])
					me = x;
		cout << dp[b[i]][me];
		i ++;
		j -= me;
	}
	cout << endl;
}