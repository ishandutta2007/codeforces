#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

pair<int,int> p[maxn];
int a[maxn], c[maxn];
vector<pair<int,int>> g[maxn];
ll dp[maxn];

ll dijkstra(int src, int snk){
	memset(dp, 63, sizeof dp);
	dp[src] = 0;
	set<pair<ll,int>> S;
	S.insert({dp[src],src});
	while (!S.empty()){
		int v = (*S.begin()).second;
		S.erase(S.begin());
		for (auto [u,w] : g[v])
			if (dp[u] > dp[v] + w){
				S.erase({dp[u],u});
				dp[u] = dp[v] + w;
				S.insert({dp[u],u});
			}
	}
	return dp[snk];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll answer = 0;
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	sort(p, p+n);
	for (int i = 0; i < n; i++){
		a[i] = p[i].first;
		c[i] = p[i].second;
		answer += c[i];
	}
	for (int i = 1; i < n; i++)
		g[i].push_back({i-1,0});
	for (int i = 0; i < n-1; i++){
		int nex = upper_bound(a, a+n, a[i]+c[i]) - a;
		if (nex < n)
			g[i].push_back({nex, a[nex]-a[i]-c[i]});
		nex--;
		if (nex != i)
			g[i].push_back({nex, 0});
	}
	cout << answer + dijkstra(0,n-1) << endl;
}