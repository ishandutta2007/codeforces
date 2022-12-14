#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 3e5 + 10;
const int inf = 1e9;

int answer;
int par[maxn], w[maxn];
int a[maxn];
int fi[maxn], se[maxn];
ll dp[maxn], pd[maxn];

pair<int,int> get_par(int v){
	if (par[v] < 0)
		return {v, 0};
	auto it = get_par(par[v]);
	return {it.first, it.second ^ w[v]};
}

void merge(int v, int u, bool wei){
	int pv = get_par(v).first, pu = get_par(u).first;
	int wv = get_par(v).second, wu = get_par(u).second;
	if (pv == pu)
		return;
	answer -= min(dp[pv], pd[pv]);
	answer -= min(dp[pu], pd[pu]);
	if (par[pv] < par[pu]){
		swap(v, u);
		swap(pv, pu);
		swap(wv, wu);
	}
	par[pu] += par[pv];
	par[pv] = pu;
	wei ^= 1;
	w[pv] = (wv ^ wu ^ wei);
	if (w[pv] == 0){
		dp[pu] += dp[pv];
		pd[pu] += pd[pv];
	}
	else{
		dp[pu] += pd[pv];
		pd[pu] += dp[pv];
	}
	answer += min(dp[pu], pd[pu]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string init;
	cin >> init;
	for (int i = 0; i < n; i++)
		if (init[i] == '1')
			a[i] = 1;
	memset(fi, -1, sizeof fi);
	memset(se, -1, sizeof se);
	for (int i = 0; i < k; i++){
		int c;
		cin >> c;
		for (int j = 0; j < c; j++){
			int x;
			cin >> x;
			x --;
			if (fi[x] == -1)
				fi[x] = i;
			else
				se[x] = i;
		}
	}
	for (int i = 0; i < k; i++){
		par[i] = -1;
		dp[i] = 1, pd[i] = 0;
	}
	for (int i = 0; i < n; i++){
		int v = fi[i], u = se[i];
		if (v == -1){
			cout << answer << '\n';
			continue;
		}
		if (u == -1){
			bool x = (a[i] & 1);
			auto it = get_par(v);
			int p = it.first, h = it.second;
			bool y = !(h & 1);
			answer -= min(dp[p], pd[p]);
			if (x ^ y)
				pd[p] = inf;
			else
				dp[p] = inf;
			answer += min(dp[p], pd[p]);
			cout << answer << '\n';
			continue;
		}
		merge(v, u, a[i]);
		cout << answer << '\n';
	}
}