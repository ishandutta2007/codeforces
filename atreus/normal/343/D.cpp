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
const int maxn = 5e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int mytime = 1, a[maxn], st[maxn], fi[maxn], seg1[4 * maxn], seg2[4 * maxn], h[maxn];
vector <int> v[maxn];

ll get2 (int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg2[id];
	int mid = (L + R) / 2;
	ll ret = 0;
	if (l < mid)
		ret = max (ret, get2 (2 * id + 0, L, mid, l, min (mid, r)));
	if (mid < r)
		ret = max (ret, get2 (2 * id + 1, mid, R, max (l, mid), r));
	return ret;
}

void change2 (int id, int L, int R, int idx, int val){
	seg2[id] = val;
	if (L + 1 == R)
		return;
	int mid = (L + R) / 2;
	if (mid > idx)
		change2 (2 * id + 0, L, mid, idx, val);
	else
		change2 (2 * id + 1, mid, R, idx, val);
}

ll get1 (int id, int L, int R, int idx){
	if (L + 1 == R)
		return seg1[id];
	ll ret = seg1[id];
	int mid = (L + R) / 2;
	if (idx < mid)
		ret = max (ret, get1 (2 * id + 0, L, mid, idx));
	else
		ret = max (ret, get1 (2 * id + 1, mid, R, idx));
	return ret;
}

void change1 (int id, int L, int R, int l, int r, int val){
	if (L == l and R == r){
		seg1[id] = val;
		return;
	}
	int mid = (L + R) / 2;
	if (l < mid)
		change1 (2 * id + 0, L, mid, l, min (mid, r), val);
	if (mid < r)
		change1 (2 * id + 1, mid, R, max (l, mid), r, val);
	return;
}

void dfs (int u, int par = -1){
	st[u] = mytime;
	mytime ++;
	for (auto w : v[u])
		if (w != par)
			dfs (w, u);
	fi[u] = mytime;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	dfs (1); 
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++){
		int type, u;
		cin >> type >> u;
		if (type == 1)
			change1 (1, 1, n + 1, st[u], fi[u], i);
		else if (type == 2)
			change2 (1, 1, n + 1, st[u], i);
		else {
			ll tmp1 = get1 (1, 1, n + 1, st[u]);
			ll tmp2 = get2 (1, 1, n + 1, st[u], fi[u]);
			cout << (tmp1 > tmp2) << '\n';
		}
	}
}