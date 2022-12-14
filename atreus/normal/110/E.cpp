#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;

int par[maxn];

int get_par(int v){
	return par[v] < 0 ? v : par[v] = get_par(par[v]);
}
void merge(int v, int u){
	v = get_par(v), u = get_par(u);
	par[v] += par[u];
	par[u] = v;
}

bool lucky(int x){
	while (x){
		if (x % 10 != 4 and x % 10 != 7)
			return 0;
		x /= 10;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(par, -1, sizeof par);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u, w;
		cin >> v >> u >> w;
		v --, u --;
		if (!lucky(w))
			merge(v, u);
	}
	ll answer = 0;
	for (int v = 0; v < n; v++){
		int sz = -par[get_par(v)];
		if (sz)
			answer += 1ll * (n - sz) * (n - sz - 1);
	}
	cout << answer << endl;
}