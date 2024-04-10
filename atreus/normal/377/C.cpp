/**
 *    author:  Atrues
 *    created: 25.01.2019 18:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int s[120], team[22];
char type[22];
int dp[22][(1 << 20) + 10];

int smin(int fi, int se){
	if (fi > 100 * 1000000)
		return se;
	return min(fi, se);
}

int smax(int fi, int se){
	if (fi > 100 * 1000000)
		return se;
	return max(fi, se);
}

int cntbit(int mask){
	int ret = 0;
	while (mask){
		ret ++;
		mask -= mask & -mask;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(dp, 63, sizeof dp);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n, greater<int>());
	int m;
	cin >> m;
	n = min(n, m);
	for (int i = 0; i < m; i++)
		cin >> type[i] >> team[i];
	dp[m][0] = 0;
	for (int i = m - 1; i >= 0; i--){
		for (int mask = 0; mask < (1 << n); mask++){
			if (cntbit(mask) != m - i)
				continue;
			for (int j = 0; j < n; j++){
				if (mask & (1 << j)){
					if (team[i] == 1){
						bool wh = (type[i] == 'p');
						dp[i][mask] = smax(dp[i][mask], dp[i + 1][mask ^ (1 << j)] + wh * s[j]);
					}
					else{
						bool wh = (type[i] == 'p');
						dp[i][mask] = smin(dp[i][mask], dp[i + 1][mask ^ (1 << j)] - wh * s[j]);
					}
				}
			}
		}
	}
	cout << dp[0][(1 << m) - 1] << endl;
}