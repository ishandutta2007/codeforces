#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

const ll maxn = 1e6 + 10;

vector<int> t[maxn];
int par[maxn], a[maxn];
bool mark[maxn];

int get_par(int v){
	return par[v] < 0 ? v : par[v] = get_par(par[v]);
}

void merge(int v, int u){
	v = get_par(v), u = get_par(u);
	if (par[v] > par[u])
		swap(v, u);
	par[u] += par[v];
	par[v] = u;
}

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	vector<pair<int, int> > vals;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		vals.push_back({a[i], i});
	}
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	sort(vals.begin(), vals.end());
	ll answer = 0;
	memset(par, -1, sizeof par);
	for (int i = 0; i < n; i++){
		int v = vals[i].second;
		int sz = 1;
		for (auto u : t[v]){
			if (mark[u] == 1){
				int w = get_par(u);
				int nowsz = -par[w];
				answer += 1ll * a[v] * sz * nowsz;
				sz += nowsz;
				merge(v, u);
			}
		}
		mark[v] = 1;
	}
	memset(par, -1, sizeof par);
	memset(mark, 0, sizeof mark);
	for (int i = n - 1; i >= 0; i--){
		int v = vals[i].second;
		int sz = 1;
		for (auto u : t[v]){
			if (mark[u] == 1){
				int w = get_par(u);
				int nowsz = -par[w];
				answer -= 1ll * a[v] * sz * nowsz;
				sz += nowsz;
				merge(v, u);
			}
		}
		mark[v] = 1;
	}
	cout << answer << endl;
}