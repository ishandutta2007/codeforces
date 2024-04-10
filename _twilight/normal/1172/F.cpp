#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long
#define pll pair<ll, ll>

const int N = 1e6 + 5;
const ll llf = 1e16;

int n, m, p;
int a[N];
vector<pll> f[N << 1];
int L[N << 1], R[N << 1];

vector<pll> merge(vector<pll>& a, vector<pll>& b) {
	vector<pll> f, g;
	int n = a.size(), m = b.size();
	int pb = 0;
	ll x = -llf, y;
//	cerr << "waw===============" << '\n';
	for (int i = 0; i < n; ) {
		y = x - a[i].first + a[i].second;
		while (pb + 1 < m && b[pb + 1].first <= y)
			pb++;
		while (pb && b[pb].first > y)
			pb--;
		ll da = ((i + 1) == n) ? (llf) : (a[i + 1].first - x);
		ll db = ((pb + 1) == m) ? (llf) : (b[pb + 1].first - y);
		f.emplace_back(x, y - b[pb].first + b[pb].second);
		if (da <= db) {
			i++;
		}
		x += min(da, db);
//		cerr << x << " " << y << " " << da << " " << db << '\n';
	}
	pll cur;
	boolean empty = true;
	for (auto v : f) {
		if (empty) {
			cur = v;
			empty = false;
		} else if (v.first - cur.first + cur.second != v.second) {
			g.push_back(cur);
			cur = v;
		}
	}
	g.push_back(cur);
	return g;
}

int __cnt = 0;
void build(int& p, int l, int r) {
	p = ++__cnt;
	if (l == r) {
		f[p].emplace_back(-llf, -llf + a[l]);
		f[p].emplace_back(::p - a[l], 0);
		return;
	}
	int mid = (l + r) >> 1;
	build(L[p], l, mid);
	build(R[p], mid + 1, r);
	f[p] = merge(f[L[p]], f[R[p]]);
}

void query(int p, int l, int r, int ql, int qr, ll& v) {
	if (l == ql && r == qr) {
		int L = 0, R = (signed) f[p].size() - 1, mid;
		while (L <= R) {
			mid = (L + R) >> 1;
			if (f[p][mid].first <= v) {
				L = mid + 1;
			} else {
				R = mid - 1;
			}
		}
		L--;
		v = v - f[p][L].first + f[p][L].second;
		return;
	}
	int mid = (l + r) >> 1;
	if (qr <= mid) {
		query(L[p], l, mid, ql, qr, v);
	} else if (ql > mid) {
		query(R[p], mid + 1, r, ql, qr, v);
	} else {
		query(L[p], l, mid, ql, mid, v);
		query(R[p], mid + 1, r, mid + 1, qr, v);
	}
}
ll query(int l, int r) {
	ll rt = 0;
	query(1, 1, n, l, r, rt);
	return rt;
}

int main() {
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	int l, r;
	build(l, 1, n);
	while (m--) {
		scanf("%d%d", &l, &r);
		printf("%lld\n", query(l, r));
	}
	return 0;
}