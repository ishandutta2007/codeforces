#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;

const int maxn = 1e5 + 10;

int seg[4 * maxn], lazy[4 * maxn], cnt[4 * maxn];

void propagate(int, int, int);

void change(int id, int L, int R, int l, int r, int val){
	if (L == l and R == r){
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	if (mid > l)
		change(2 * id + 0, L, mid, l, min(mid, r), val);
	if (mid < r)
		change(2 * id + 1, mid, R, max(l, mid), r, val);
	seg[id] = min(seg[2 * id + 0], seg[2 * id + 1]);
	cnt[id] = (seg[2 * id + 0] == seg[id]) * cnt[2 * id + 0] + (seg[2 * id + 1] == seg[id]) * cnt[2 * id + 1];
}

void propagate(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, lazy[id]);
	change(2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

void build(int id, int L, int R){
	cnt[id] = R - L;
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
}

int Time = 1, st[maxn], ft[maxn];;
int n;

vector <int> t[maxn];

void dfs_st(int v, int par = -1){
	st[v] = Time ++;
	for (auto u : t[v])
		if (u != par)
			dfs_st(u, v);
	ft[v] = Time;
}

int answer[maxn];

vector <int> tilnow, List[maxn];

pii q[maxn];

void dfs(int v, int par = -1){
	for (auto it : List[v]){
		int u = q[it].first;
		change(1, 1, n + 1, st[u], ft[u], +1);
		u = q[it].second;
		change(1, 1, n + 1, st[u], ft[u], +1);
	}
	
	if (seg[1] > 0)
		answer[v] = n - 1;
	else
		answer[v] = n - cnt[1] - 1;
	
	for (auto u : t[v])
		if (u != par)
			dfs(u, v);
	for (auto it : List[v]){
		int u = q[it].first;
		change(1, 1, n + 1, st[u], ft[u], -1);
		u = q[it].second;
		change(1, 1, n + 1, st[u], ft[u], -1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs_st(1);
	for (int i = 0; i < m; i++){
		cin >> q[i].first >> q[i].second;
		List[q[i].first].push_back(i);
		List[q[i].second].push_back(i);
	}
	build(1, 1, n + 1);
	dfs(1);
	for (int i = 1; i <= n; i++)
		cout << max(answer[i], 0) << " ";
	cout << endl;
}