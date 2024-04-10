#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int mod = 998244353;

int dp[maxn];
vector<int> g[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			g[i].clear();
		int m;
		cin >> m;
		for (int i = 1; i <= m; i++){
			int v, u;
			cin >> v >> u;
			g[u].push_back(v);
		}
		vector<int> a;
		for (int i = 1; i <= n; i++){
			dp[i] = 1;
			for (auto u : g[i])
				dp[i] = max(dp[i], dp[u] + 1);
			if (dp[i] == 3){
				dp[i] = -1;
				a.push_back(i);
			}
		}
		cout << a.size() << '\n';
		for (auto v : a)
			cout << v << " ";
		cout << '\n';
	}
}