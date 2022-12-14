#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <bitset>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 4e5 + 10;
const int maxm = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9;
const int sq = 400;

vector <int> t[maxn];

int lazy[4 * maxn];
bitset <65> seg[4 * maxn];
inline void propagate (int, int, int);

bitset <65> get (int id, int L, int R, int l, int r) {
	if (L == l and R == r)
		return seg[id];
	propagate (id, L, R);
	int mid = (L + R) >> 1;
	bitset <65> ret;
	ret.reset();
	if (mid > l)
		ret |= get (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		ret |= get (2 * id + 1, mid, R, max (l, mid), r);
	return ret;
}

void change (int id, int L, int R, int l, int r, int col) {
	if (L == l and R == r) {
		seg[id].reset();
		seg[id][col] = 1;
		lazy[id] = col;
		return;
	}
	propagate (id, L, R);
	int mid = (L + R) >> 1;
	if (mid > l)
		change (2 * id + 0, L, mid, l, min (mid, r), col);
	if (mid < r)
		change (2 * id + 1, mid, R, max (l, mid), r, col);
	seg[id] = (seg[2 * id + 0] | seg[2 * id + 1]);
}

void propagate (int id, int L, int R) {
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	change (2 * id + 0, L, mid, L, mid, lazy[id]);
	change (2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

int st[maxn], ft[maxn];

int Time = 0;
void dfs (int v, int par = -1) {
	st[v] = Time ++;
	for (auto w : t[v])
		if (w != par)
			dfs (w, v);
	ft[v] = Time;
}

int c[maxn];

int main () {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];

	for (int i = 1; i <= n - 1; i++) {
		int v, u;
		cin >> v >> u;
		t[v].PB (u);
		t[u].PB (v);
	}

	dfs (1);
	
	for (int i = 1; i <= n; i++)
		change (1, 0, n, st[i], st[i] + 1, c[i]);

	for (int i = 1; i <= m; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int v, x;
			cin >> v >> x;
			change (1, 0, n, st[v], ft[v], x);
		}
		else {
			int v;
			cin >> v;
			bitset <65> bs = get (1, 0, n, st[v], ft[v]);
			cout << bs.count () << endl;
		}
	}
}