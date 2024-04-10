#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define sz(a) (int)(a).size()
#define mp make_pair

using namespace std;

typedef long long ll;

vector<vector<int>> gr, ans;
map<pair<int,int>, int> rn;

void dfs(int v, int p, int e) {
	int x = 0;
	for(int to : gr[v])
		if(to != p) {
			if(x == e)
				x++;
			ans[x].pb(rn[mp(v, to)]);
			dfs(to, v, x);
			x++;
		}
}

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	gr.resize(n);
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		gr[u].pb(v);
		gr[v].pb(u);
		rn[mp(u, v)] = i;
		rn[mp(v, u)] = i;
	}
	int k = 0;
	for(int i = 0; i < n; i++)
		k = max(k, sz(gr[i]));
	cout << k << "\n";
	ans.resize(k);
	dfs(0, -1, -1);
	for(int i = 0; i < k; i++, cout << "\n") {
		cout << sz(ans[i]);
		for(int w : ans[i])
			cout << ' ' << w;
	}
}