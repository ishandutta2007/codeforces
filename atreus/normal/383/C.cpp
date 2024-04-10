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
const int inf = (1 << 30);
int mytime = 1, a[maxn], st[maxn], fi[maxn], seg[4 * maxn][5], h[maxn];
vector <int> v[maxn];

ll get (int id, int L, int R, int idx, int hei){
	ll ret = seg[id][hei] - seg[id][1 - hei];
	if (L + 1 == R)
		return ret;
	int mid = (L + R) / 2;
	if (mid > idx)
		ret += get (2 * id + 0, L, mid, idx, hei);
	else
		ret += get (2 * id + 1, mid, R, idx, hei);
	return ret;
}

void change (int id, int L, int R, int l, int r, bool h, int val){
	if (L == l and R == r){
		seg[id][h] += val;
		return;
	}
	int mid = (L + R) / 2;
	if (l < mid)
		change (2 * id + 0, L, mid, l, min (mid, r), h, val);
	if (mid < r)
		change (2 * id + 1, mid, R, max (l, mid), r, h, val);
}

void dfs (int u, int height, int par = -1){
	st[u] = mytime;
	h[u] = height % 2;
	mytime ++;
	for (auto w : v[u])
		if (w != par)
			dfs (w, height + 1, u);
	fi[u] = mytime;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	dfs (1, 1);
	for (int i = 1; i <= q; i++){
		int type;
		cin >> type;
		if (type == 1){
			int u, val;
			cin >> u >> val;
			change (1, 1, n + 1, st[u], fi[u], h[u], val);
		}
		else {
			int u;
			cin >> u;
			cout << a[u] + get (1, 1, n + 1, st[u], h[u]) << endl;
		}
	}
}