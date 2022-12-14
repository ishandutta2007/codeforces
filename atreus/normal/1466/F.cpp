#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 5e5 + 10;
const ll mod = 1e9 + 7;

int par[maxn];
bool hascycle[maxn];

int get_par(int v){
	return par[v] < 0 ? v : par[v] = get_par(par[v]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> opt;
	int T = 1;
	memset(par, -1, sizeof par);
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		if (k == 1){
			int x;
			cin >> x;
			x = get_par(x);
			if (hascycle[x])
				continue;
			hascycle[x] = 1;
			opt.push_back(i);
			T = 2LL*T%mod;
			continue;
		}
		int v, u;
		cin >> v >> u;
		v = get_par(v), u = get_par(u);
		if (v != u){
			par[v] = u;
			if (hascycle[v] and hascycle[u])
				continue;
			hascycle[u] |= hascycle[v];
			opt.push_back(i);
			T = 2LL*T%mod;
			continue;
		}
	}
	cout << T << " " << opt.size() << '\n';
	for (auto it : opt)
		cout << it << " ";
	cout << '\n';
}