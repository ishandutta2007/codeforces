#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define position first
#define sizze second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 2e5 + 10;
const int MaxA = 1e6 + 10;
const int mod = 1e9 + 7;

struct node {
	ll mul;
	ll sr;
	ll mr;
	node (ll mul_, ll sr_, ll mr_) {
		mul = mul_, sr = sr_, mr = mr_;
	}
	node () {
		mul = 0, sr = 0, mr = 0;
	}
};

ll power (ll a, ll b) {
	if (b == 0)
		return 1;
	ll ret = power (a, b / 2);
	ret = ret * ret % mod;
	if (b & 1)
		ret = ret * a % mod;
	return ret;
}

int mpf[MaxA];
void sieve (int m) {
	mpf[1] = 1;
	for (int i = 2; i <= m; i++)
		if (mpf[i] == 0) 
			for (int j = i; j <= m; j+=i)
				mpf[j] = i;
}

int a[maxn], n;

node seg[4 * maxn];

node merge (node fi, node se) {
	if (fi.mul == 0)
		swap (fi, se);
	if (se.mul == 0)
		return fi;
	return node (fi.mul * se.mul % mod, fi.sr * se.sr % mod, fi.mr * se.mr % mod);
}

node get (int id, int L, int R, int l, int r) {
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) >> 1;
	node fi, se;
	if (mid > l) 
		fi = get (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		se = get (2 * id + 1, mid, R, max (l, mid), r);
	return merge (fi, se);
}

void change (int id, int L, int R, int idx, ll fi, ll se) {
	seg[id].sr = seg[id].sr * fi % mod;
	seg[id].mr = seg[id].mr * se % mod;
	
	if (L + 1 == R)
		return;
	
	int mid = (L + R) >> 1;
	if (mid > idx)
		change (2 * id + 0, L, mid, idx, fi, se);
	else
		change (2 * id + 1, mid, R, idx, fi, se);
}

ll build (int id, int L, int R) {
	seg[id].sr = seg[id].mr = 1;
	if (L + 1 == R) {
		seg[id].mul = a[L];
		return seg[id].mul;
	}
	int mid = (L + R) >> 1;
	seg[id].mul = build (2 * id + 0, L, mid) * build (2 * id + 1, mid, R) % mod;
	return seg[id].mul;
}	

ll rev[MaxA];

int last[MaxA];
void add (int idx) {
	int m = -1, x = a[idx];
	while (x > 1) {
		if (mpf[x] != m) {
			m = mpf[x];
			if (last[m])
				change (1, 1, n + 1, last[m], rev[m - 1], rev[m]);
			
			last[m] = idx;
			change (1, 1, n + 1, last[m], m - 1, m);
		}
		x /= mpf[x];
	}
}

ll ans[maxn];
vector <pii> v[maxn];
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int max_number = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		max_number = max (max_number, a[i]);
	}

	sieve (max_number);
	for (int i = 1; i <= max_number; i++)
		rev[i] = power (i, mod - 2);

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		v[r].PB ({l, i});
	}
	
	build (1, 1, n + 1);
	
	for (int i = 1; i <= n; i++) {
		add (i);
		for (auto u : v[i]) {
			int l = u.first, andice = u.second;
			node m = get (1, 1, n + 1, l, i + 1);
			ans[andice] = m.mul * m.sr % mod * power (m.mr, mod - 2) % mod;
		}
	}
	
	for (int i = 0; i < Q; i++)
		cout << ans[i] << '\n';
	return 0;
}