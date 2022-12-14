#include <bits/stdc++.h>

#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const ll inf = 1e18 + 1;
const int maxn = 1e5 + 10;
const int maxm = 1000;

bitset <maxm> seg[4 * maxn], mab;
int lazy[4 * maxn];
int st[maxn], ft[maxn], pos[maxn], a[maxn];
vector <int> t[maxn];
int m = 10;

void propagate (int, int, int);

bitset <maxm> shift (bitset <maxm> id, int x) {
	bitset <maxm> tmp = (id << x);
	id = tmp ^ (id >> (m - x));
	return id & mab;
}

bitset <maxm> get (int id, int L, int R, int l, int r) {
	if (L == l and R == r)
		return seg[id];
	propagate (id, L, R);
	int mid = (L + R) >> 1;
	if (mid >= r)
		return get (2 * id + 0, L, mid, l, r);
	if (mid <= l)
		return get (2 * id + 1, mid, R, l, r);
	return get (2 * id + 0, L, mid, l, mid) | get (2 * id + 1, mid, R, mid, r);
}

void change (int id, int L, int R, int l, int r, int x) {
	if (L == l and R == r) {
		seg[id] = shift (seg[id], x);
		lazy[id] = (lazy[id] + x) % m;
		return;
	}
	propagate (id, L, R);
	int mid = (L + R) >> 1;
	if (mid > l)
		change (2 * id + 0, L, mid, l, min (mid, r), x);
	if (mid < r)
		change (2 * id + 1, mid, R, max (l, mid), r, x);
	seg[id] = seg[2 * id + 0] | seg[2 * id + 1];
}

void propagate (int id, int L, int R) {
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	change (2 * id + 0, L, mid, L, mid, lazy[id]);
	change (2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

void build (int id, int L, int R) {
	if (L + 1 == R) {
		seg[id][a[pos[L]]] = 1;
		return;
	}
	int mid = (L + R) >> 1;
	build (2 * id + 0, L, mid);
	build (2 * id + 1, mid, R);
	seg[id] = seg[2 * id + 0] | seg[2 * id + 1];
}

int T;
void dfs (int v, int par = -1) {
	st[v] = T, pos[T ++] = v;
	for (auto u : t[v])
		if (u != par)
			dfs (u, v);
	ft[v] = T;
}

bool isprime (int x) {
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		mab[i] = 1;
	vector <int> primes;
	for (int i = 2; i <= m; i++)
		if (isprime (i))
			primes.PB (i);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] %= m;
	}
	
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		v --, u --;
		t[v].PB (u);
		t[u].PB (v);
	}
	dfs (0);
	build (1, 0, n);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int type, v;
		cin >> type >> v;
		v --;
		if (type == 1) {
			int x;
			cin >> x;
			x %= m;
			change (1, 0, n, st[v], ft[v], x);
		}
		else {
			bitset <maxm> bs = get (1, 0, n, st[v], ft[v]);
			int cnt = 0;
			for (auto p : primes) {
				if (bs[p] == 1) {
					cnt ++;
				}
			}
			cout << cnt << '\n';
		}
	}
}