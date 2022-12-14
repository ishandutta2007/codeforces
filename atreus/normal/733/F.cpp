#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;
const int M = 1e5 + 10;
const ll inf = (1ll << 60);
ll par[maxn], p[maxn][50], dp[maxn][50], h[maxn], ans[maxn];
bool visited[maxn];
pair <pair <ll, ll>, pair <ll, ll> > ed[maxn];
vector <pair <ll, ll> > v[maxn];

ll getpar (ll u){
	if (par[u] < 0)
		return u;
	return par[u] = getpar (par[u]);
}

void merge (ll u, ll w){
	if (par[u] > par[w])
		swap (u, w);
	par[w] += par[u];
	par[w] = u;
	return;
}

void dfs (ll u, ll parent, ll wei, ll hei){
	visited[u] = 1;
	p[u][0] = parent;
	dp[u][0] = wei;
	h[u] = hei;
	for (auto w : v[u])
		if (!visited[w.F])
			dfs (w.F, u, w.S, hei + 1);
}

ll get (ll u, ll w){
	ll ret = -1;
	if (h[u] > h[w])
		swap (u, w);
	for (int i = 30; i >= 0; i--){
		if (h[w] - (1ll << i) >= h[u]){
			ret = max (ret, dp[w][i]);
			w = p[w][i];
		}
	}
	if (u == w)
		return ret;
	for (int i = 30; i >= 0; i--){
		if (p[u][i] != p[w][i]){
			ret = max (ret, dp[u][i]);
			ret = max (ret, dp[w][i]);
			u = p[u][i];
			w = p[w][i];
		}
	}
	ret = max (ret, max (dp[u][0], dp[w][0]));
	return ret;
}



int c[maxn], weight[maxn];

pair <int, int> edge[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
	    cin >> ed[i].F.F;
        weight[i] = ed[i].F.F;
	}
	for (int i = 1; i <= m; i++)
	    cin >> c[i];
	for (int i = 1; i <= m; i++){
		cin >> ed[i].S.F >> ed[i].S.S;
		ed[i].F.S = i;
		edge[i].F = ed[i].S.F, edge[i].S = ed[i].S.S;
	}
	sort (ed + 1, ed + m + 1);
	ll mst = 0;
	memset (par, -1, sizeof par);
	for (int i = 1; i <= m; i++){
		ll u = getpar (ed[i].S.F), w = getpar (ed[i].S.S);
		if (u != w){	
			merge (u, w);
			mst += ed[i].F.F;
			v[ed[i].S.F].PB (MP (ed[i].S.S, ed[i].F.F));
			v[ed[i].S.S].PB (MP (ed[i].S.F, ed[i].F.F));
		}
	}
	dfs (1, 0, -1, 0);
	for (int i = 1; i <= 30; i++){
		for (int j = 1; j <= n; j++){
			ll u = p[j][i - 1];
			p[j][i] = p[u][i - 1];
			dp[j][i] = max (dp[j][i - 1], dp[u][i - 1]);
		}
	}
	for (int i = 1; i <= m; i++){
		ll u = ed[i].S.F, w = ed[i].S.S, idx = ed[i].F.S, wei = ed[i].F.F;
		ll tmp = get (u, w);
		ans[idx] = mst - tmp + wei;
	}
	int pqq;
	cin >> pqq;
	ll cnt = inf;
	int qpp;
	for (int i = 1; i <= m; i++) {
    	if (ans[i] - pqq / c[i] < cnt) {
	        cnt = min (cnt, ans[i] - pqq / c[i]);
	        qpp = i;
    	}
    }

	cout << cnt << '\n';
	memset (par, -1, sizeof par);
	cout << qpp << " " << weight[qpp] - pqq / c[qpp] << '\n';
	merge (edge[qpp].F, edge[qpp].S);
    for (int i = 1; i <= m; i++) {
        ll u = ed[i].S.F, w = ed[i].S.S;
        if ((u = getpar (u)) != (w = getpar (w))) {
            merge (u, w);
            cout << ed[i].F.S << " " << weight[ed[i].F.S] << '\n';
        }  
    }
}