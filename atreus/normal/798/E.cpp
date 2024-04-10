#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 5e5 + 10;
const int maxl = 23;

vector<int> g[maxn * maxl];

int lc[maxn*maxl], rc[maxn*maxl];
int cnt;

int change(int id, int L, int R, int idx){
	if (L > idx or R <= idx)
		return id;
	if (L + 1 == R)
		return 0;
	int newid = cnt ++;
	int mid = (L + R) >> 1;
	lc[newid] = change(lc[id], L, mid, idx);
	rc[newid] = change(rc[id], mid, R, idx);
	g[newid].push_back(lc[newid]);
	g[newid].push_back(rc[newid]);
	return newid;
}

void add(int id, int L, int R, int l, int r, int u){
	if (L == l and R == r){
		g[u].push_back(id);
		return;
	}
	int mid = (L + R) >> 1;
	if (l < mid)
		add(lc[id], L, mid, l, min(mid, r), u);
	if (mid < r)
		add(rc[id], mid, R, max(l, mid), r, u);
}

int build(int L, int R){
	if (L + 1 == R)
		return L;
	int id = cnt ++;
	int mid = (L + R) >> 1;
	lc[id] = build(L, mid);
	rc[id] = build(mid, R);
	g[id].push_back(lc[id]);
	g[id].push_back(rc[id]);
	return id;
}

vector<int> topol;
bool visited[maxn * maxl];

void dfs(int v){
	visited[v] = 1;
	for (auto u : g[v])
		if (!visited[u])
			dfs(u);
	topol.push_back(v);
}

int a[maxn], p[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cnt = n + 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int root = build(1, n + 1);
	for (int i = 1; i <= n; i++){
		if (a[i] == -1){
			if (i > 1)
				add(root, 1, n + 1, 1, i, i);
			if (i < n)
				add(root, 1, n + 1, i + 1, n + 1, i);
		}
		else{
			if (a[i] > 1){
				if (i >= a[i])
					add(root, 1, n + 1, 1, a[i], i);
				else{
					if (i > 1)
						add(root, 1, n + 1, 1, i, i);
					if (a[i] > i + 1)
					add(root, 1, n + 1, i + 1, a[i], i);
				}
			}
			g[a[i]].push_back(i);
			root = change(root, 1, n + 1, a[i]);
		}
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			dfs(i);
	int tmp = 1;
	for (auto it : topol)
		if (it <= n and it >= 1)
			p[it] = tmp ++;
	for (int i = 1; i <= n; i++)
		cout << p[i] << " ";
	cout << endl;
}