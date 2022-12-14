#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int maxl = 20;
const int inf = 1e9 + 1;

int n, a[maxn];

int Time = 1, st[maxn], ft[maxn];
vector<int> t[maxn];
int lc[maxn * maxl], rc[maxn * maxl], seg[maxn * maxl];

int get(int node, int L, int R, int l, int r){
	if (R <= l or r <= L)
		return inf;
	if (l <= L and R <= r)
		return seg[node];
	int mid = (L + R) >> 1;
	return min(get(lc[node], L, mid, l, r), get(rc[node], mid, R, l, r));
}

int newint = 1;
int add(int node, int L, int R, int idx, int val){
	if (idx < L or idx >= R)
		return node;
	int mynode = newint ++;
	if (L + 1 == R){
		seg[mynode] = val;
		return mynode;
	}
	int mid = (L + R) >> 1;
	lc[mynode] = add(lc[node], L, mid, idx, val);
	rc[mynode] = add(rc[node], mid, R, idx, val);
	seg[mynode] = min(seg[lc[mynode]], seg[rc[mynode]]);
	return mynode;
}

int root[maxn];

int q[maxn], h[maxn];
void bfs(int r){
	memset(h, -1, sizeof h);
	h[r] = 0;
	int lastroot = 0;
	seg[0] = inf;

	int head = 0, tail = 0;
	q[tail++] = r;
	while (head < tail){
		int v = q[head++];
		root[h[v]] = add(lastroot, 1, n + 1, st[v], a[v]);
		lastroot = root[h[v]];
		for (auto u : t[v]){
			if (h[u] == -1){
				h[u] = h[v] + 1;
				q[tail++] = u;
			}
		}
	}
}

void dfs(int v, int par = -1){
	st[v] = Time ++;
	for (auto u : t[v])
		if (u != par)
			dfs(u, v);
	ft[v] = Time;
}

int main(){
	ios_base::sync_with_stdio(false);
	int r;
	cin >> n >> r;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(r);
	bfs(r);
	int maxheight = *max_element(h + 1, h + n + 1);
	int m;
	cin >> m;
	int last = 0;
	for (int i = 1; i <= m; i++){
		int p, q;
		cin >> p >> q;
		int x = ((p + last) % n) + 1, k = ((q + last) % n);
		int height = min(maxheight, h[x] + k);
		last = get(root[height], 1, n + 1, st[x], ft[x]);
		cout << last << '\n';
	}
}