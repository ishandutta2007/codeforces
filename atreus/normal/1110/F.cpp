/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 5e5 + 10;
const ll inf = 1e15;

ll dis[maxn], seg[4 * maxn], lazy[4 * maxn];
vector<pair<int, int> > t[maxn];

void propagate(int, int, int);

ll get(int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	ll ret = inf;
	if (l < mid)
		ret = min(ret, get(2 * id + 0, L, mid, l, min(mid, r)));
	if (mid < r)
		ret = min(ret, get(2 * id + 1, mid, R, max(l, mid), r));
	return ret;
}

void add(int id, int L, int R, int l, int r, ll val){
	if (L == l and R == r){
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	if (l < mid)
		add(2 * id + 0, L, mid, l, min(mid, r), val);
	if (mid < r)
		add(2 * id + 1, mid, R, max(l, mid), r, val);
	seg[id] = min(seg[2 * id + 0], seg[2 * id + 1]);
}

void propagate(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, L, mid, lazy[id]);
	add(2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

vector<int> query[maxn];
ll ans[maxn];
int n, l[maxn], r[maxn], st[maxn], ft[maxn];
void dfs(int v){
	for (auto i : query[v])
		ans[i] = get(1, 1, n + 1, l[i], r[i] + 1);
	
	for (auto u : t[v]){
		add(1, 1, n + 1, 1, n + 1, u.second);
		add(1, 1, n + 1, st[u.first], ft[u.first], -2ll * u.second);
		dfs(u.first);
		add(1, 1, n + 1, 1, n + 1, -u.second);
		add(1, 1, n + 1, st[u.first], ft[u.first], +2ll * u.second);		
	}
}

int T = 1;
void fds(int v){ // find_distance_(from)source
	st[v] = T++;
	for (auto u : t[v]){
		dis[u.first] = dis[v] + u.second;
		fds(u.first);
	}
	ft[v] = T;
	if (t[v].size() > 0)
		dis[v] = inf;
	add(1, 1, n + 1, v, v + 1, dis[v]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int q;
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++){
		int v, w;
		scanf("%d%d", &v, &w);
		t[v].push_back({i, w});
	}
	fds(1);
	for (int i = 0; i < q; i++){
		int v;
		scanf("%d%d%d", &v, &l[i], &r[i]);
		query[v].push_back(i);
	}
	dfs(1);
	for (int i = 0; i < q; i++)
		printf("%lld\n", ans[i]);
}