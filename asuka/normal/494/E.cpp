#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int N = 5e5 + 15;

namespace fastIO {
	const int SZ = 1 << 20;
	struct IO {
		char buf[SZ], *p1, *p2;
		IO() : p1(buf), p2(buf) {}
		char gc() {
			if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, SZ, stdin);

			return p1 == p2 ? ' ' : *p1++;
		}
		int read() {
			int x = 0;
			char ch = gc();

			while (!isdigit(ch)) ch = gc();

			while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch - '0'), ch = gc();

			return x;
		}
	} io;
	int read() {return io.read();};
}
using namespace fastIO;

struct node {

	int l, r, mid, cov, val, sum;
	node *ls, *rs;

	void pull() {
		if (cov) sum = val;
		else if (l == r) sum = 0;
		else sum = ls -> sum ^ rs -> sum;
	}

	void cover(int x, int y, int v) {
		if (x <= l && r <= y) {
			cov += v;
			return pull();
		}

		if (x <= mid) ls -> cover(x, y, v);

		if (mid < y) rs -> cover(x, y, v);

		pull();
	}

} Pool[N << 3], *ptr = Pool, *rt;

node* build(int l, int r, const vector<int>& vec) {
	node* p = ptr++;
	int mid = (l + r) >> 1;
	p -> l = l; p -> r = r; p -> mid = mid;
	p -> val = vec[r] ^ vec[l - 1];
	p -> cov = p -> sum = 0;


	if (l == r) return p;

	p -> ls = build(l, mid, vec); p -> rs = build(mid + 1, r, vec);
	return p;
}

struct Event {
	int x, l, r, typ;
	bool operator < (const Event &rhs) const {
		return x != rhs.x ? x < rhs.x : typ < rhs.typ;
	}
};

int n, m, k, a[N], b[N], c[N], d[N];

int main() {
	n = read(); m = read(); k = read();

	rep(i, 1, m) a[i] = read(), b[i] = read(), c[i] = read(), d[i] = read();

	vector<int> num;

	rep(i, 1, m) num.pb(b[i] - 1), num.pb(d[i]);

	sort(all(num));
	num.erase(unique(all(num)), num.end());
	rt = build(1, SZ(num) - 1, num);
	auto ID = [&](int x) {return lower_bound(all(num), x) - num.begin();};
	vector<Event> vec;

	rep(i, 1, m) {
		int l = ID(b[i] - 1) + 1, r = ID(d[i]);
		vec.pb((Event) {a[i] - 1, l, r, 1});
		vec.pb((Event) {c[i], l, r, -1});
	}

	sort(all(vec));
	int lst = 0, res = 0;

	for (auto u : vec) {
		res ^= (u.x ^ lst) & rt -> sum;

		lst = u.x;
		rt -> cover(u.l, u.r, u.typ);
	}


	int O = 1;

	while (O <= k) O <<= 1;

	res &= O - 1;

	puts(res ? "Hamed" : "Malek");

	return 0;
}