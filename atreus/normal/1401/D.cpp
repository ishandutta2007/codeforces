#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

ll p[maxn], sz[maxn], q[maxn];
vector<int> t[maxn];

int dfs(int v, int par = -1){
	sz[v] = 1;
	for (auto u : t[v])
		if (u != par)
			sz[v] += dfs(u, v);
	return sz[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 1; i <= n-1; i++){
			int v, u;
			cin >> v >> u;
			t[v].push_back(u);
			t[u].push_back(v);
		}
		int m;
		cin >> m;
		for (int i = 1; i <= m; i++)
			cin >> p[i];
		sort(p+1, p+m+1, greater<int>());
		int idx = 1, cnt = m;
		for (int i = 2; cnt > n-1; i++, idx++, cnt--)
			p[1] = 1LL*p[i]*p[1] % mod;
		for (int i = idx+1; i <= m; i++)
			p[i-idx+1] = p[i];
		for (int i = m+1; i <= n-1; i++)
			p[i] = 1;
		dfs(1);
		int answer = 0;
		for (int i = 2; i <= n; i++){
			int x = sz[i], y = n-sz[i];
			q[i-1] = 1LL*x*y;
		}
		sort(q+1, q+n, greater<ll>());
		for (int i = 1; i <= n-1; i++){
			q[i] %= mod;
			answer = (answer + 1LL*p[i]*q[i]) % mod;
		}
		cout << answer << '\n';
		for (int i = 1; i <= n; i++)
			t[i].clear();
	}
}