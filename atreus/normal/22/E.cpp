/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;

int bargs[maxn], some[maxn], par[maxn], nex[maxn];

int get_par(int v){
	return par[v] < 0 ? v : par[v] = get_par(par[v]);
}

void merge(int v, int u){
	if (get_par(v) == get_par(u)){
		some[get_par(v)] = v;
		return;
	}
	v = get_par(v), u = get_par(u);
	if (some[u] == 0)
		some[u] = some[v];
	par[v] = u;
}

int in[maxn];
vector<pair<int, int> > ans;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	memset(par, -1, sizeof par);
	for (int i = 1; i <= n; i++){
		int v;
		cin >> v;
		merge(i, v);
		in[v] ++;
	}
	for (int v = 1; v <= n; v++)
		if (in[v] == 0)
			bargs[get_par(v)] ++;
	int first = -1, last = -1;
	for (int v = 1; v <= n; v++){
		if (par[v] >= 0)
			continue;
		if (last != -1)
			nex[last] = v;
		last = v;
		if (first == -1)
			first = v;
	}
	nex[last] = first;
	if (first == last and bargs[first] == 0)
		return cout << 0 << endl, 0;
	for (int v = 1; v <= n; v++)
		if (in[v] == 0 or (par[v] < 0 and bargs[v] == 0))
			ans.push_back({some[nex[get_par(v)]], v});
	
	cout << ans.size() << endl;
	for (auto ed : ans)
		cout << ed.first << " " << ed.second << '\n';
}