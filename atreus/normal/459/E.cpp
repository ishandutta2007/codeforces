/**
 *    author:  Atreus
 *    created: 17.01.2019 18:55:00
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 3e5 + 10;
const int maxm = 3e5 + 10;

struct edge{
	int fi;
	int se;
	int w;
	bool operator < (const edge &other) const{
		return w < other.w;
	}
};

edge e[maxm];

int answer;
vector <int> dp[maxn], g[maxn];

void relax(int u, int v, int idx){
	int fi = lower_bound(g[v].begin(), g[v].end(), idx) - g[v].begin() + 1;
	int se = lower_bound(g[u].begin(), g[u].end(), idx) - g[u].begin() + 1;
	dp[v][fi] = max(dp[v][fi], dp[v][fi - 1]);
	dp[u][se] = max(dp[u][se], dp[u][se - 1]);
	dp[v][fi] = max(dp[v][fi], dp[u][se - 1] + 1);
	answer = max(answer, dp[v][fi]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> e[i].fi >> e[i].se >> e[i].w;
		g[e[i].fi].push_back(e[i].w);
		g[e[i].se].push_back(e[i].w);
	}
	for (int i = 1; i <= n; i++){
		sort(g[i].begin(), g[i].end());
		g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
		dp[i].resize(g[i].size() + 5);
	}
	sort(e, e + m);
	for (int i = 0; i < m; i++)
		relax(e[i].fi, e[i].se, e[i].w);
	cout << answer << endl;
}