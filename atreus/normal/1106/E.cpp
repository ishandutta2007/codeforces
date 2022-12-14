/**
 *    author:  Atreus
 *    created: 31.01.2019 16:05
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
vector<int> st[maxn], en[maxn];
int nex[maxn], csh[maxn], s[maxn], t[maxn], d[maxn], w[maxn];
ll dp[maxn][200 + 10];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++){
		cin >> s[i] >> t[i] >> d[i] >> w[i];
		st[s[i]].push_back(i);
		en[t[i]].push_back(i);
	}
	multiset<pair<int, int> > s;
	for (int i = 1; i <= n; i++){
		for (auto it : st[i])
			s.insert({-w[it], -d[it]});
		if (!s.empty()){
			nex[i] = -(*s.begin()).second + 1;
			csh[i] = -(*s.begin()).first;
		}
		else{
			nex[i] = i + 1;
			csh[i] = 0;
		}
		for (auto it : en[i])
			s.erase(s.find({-w[it], -d[it]}));
	}
	for (int i = n + 1; i >= 1; i--){
		for (int j = 0; j <= m; j++){
			if (i == n + 1){
				dp[i][j] = 0;
				continue;
			}
			if (j == 0){
				dp[i][j] = dp[nex[i]][j] + csh[i];
				continue;
			}
			dp[i][j] = min(dp[nex[i]][j] + csh[i], dp[i + 1][j - 1]);
		}
	}
	ll answer = ll(1e18);
	for (int i = 0; i <= m; i++)
		answer = min(answer, dp[1][i]);
	cout << answer << endl;
}