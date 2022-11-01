#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
mt19937 rng(1145141);
struct Node {
	long long val, tag;
	int sz, lson, rson;
} tr[N];
int tot, rt;
inline int newnode(long long val) {
	int p = ++tot;
	tr[p].val = val;
	tr[p].tag = 0;
	tr[p].sz = 1;
	tr[p].lson = tr[p].rson = 0;
	return p;
}
inline void Tag(int p, long long tag) {
	tr[p].val += tag;
	tr[p].tag += tag;
}
inline void pushdown(int p) {
	if (tr[p].tag) {
		if (tr[p].lson) Tag(tr[p].lson, tr[p].tag);
		if (tr[p].rson) Tag(tr[p].rson, tr[p].tag);
		tr[p].tag = 0;
	}
}
inline void pushup(int p) {
	tr[p].sz = tr[tr[p].lson].sz + tr[tr[p].rson].sz + 1;
}
inline void Init() {
	tot = rt = 0;
	tr[0].val = tr[0].tag = 0;
	tr[0].sz = tr[0].lson = tr[0].rson = 0;
}
pair<int, int> Split(int p, long long k) {
	if (!p) return make_pair(0, 0);
	pushdown(p);
	pair<int, int> ret;
	if (tr[p].val >= k) {
		ret = Split(tr[p].lson, k);
		tr[p].lson = ret.second;
		ret.second = p;
	} else {
		ret = Split(tr[p].rson, k);
		tr[p].rson = ret.first;
		ret.first = p;
	}
	pushup(p);
	return ret;
}
int Merge(int p1, int p2) {
	if (!p1 || !p2) return p1 | p2;
	if (uniform_int_distribution<int>(1, tr[p1].sz + tr[p2].sz)(rng) <= tr[p1].sz) {
		pushdown(p1);
		tr[p1].rson = Merge(tr[p1].rson, p2);
		pushup(p1);
		return p1;
	} else {
		pushdown(p2);
		tr[p2].lson = Merge(p1, tr[p2].lson);
		pushup(p2);
		return p2;
	}
}
void Ins(long long val) {
	auto P = Split(rt, val);
	rt = Merge(Merge(P.first, newnode(val)), P.second);
}
int n;
long long a[N], ps[N];
int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ps[0] = 0;
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), ps[i] = ps[i - 1] + a[i];
		long long ans = 1;
		Init();
		Ins(0);
		for (int i = n - 2; i >= 2; i -= 2) {
			long long cur = a[n] + a[n - i - 1] - (ps[n - 1] - ps[n - i - 1]);
			pair<int, int> P = Split(rt, -cur);
			ans += tr[P.first].sz;
			rt = Merge(P.first, P.second);
			Tag(rt, a[n - i - 1] - a[n - i]);
			Ins(ps[n - i] - 2 * a[1]);
			Ins(ps[n - i]);
		}
		Init();
		Ins(a[1]);
		Ins(-a[1]);
		for (int i = n - 3; i >= 2; i -= 2) {
			long long cur = a[n] + a[n - i - 1] - (ps[n - 1] - ps[n - i - 1]);
			pair<int, int> P = Split(rt, -cur);
			ans += tr[P.first].sz;
			rt = Merge(P.first, P.second);
			Tag(rt, a[n - i - 1] - a[n - i]);
			Ins(ps[n - i] - 2 * a[1]);
			Ins(ps[n - i]);
		}
		Init();
		Ins(0);
		for (int i = n - 1; i >= 0; i -= 2) {
			long long cur = a[n - i] - (ps[n] - ps[n - i]);
			pair<int, int> P = Split(rt, -cur);
			ans += tr[P.first].sz;
			rt = Merge(P.first, P.second);
			Tag(rt, a[n - i] - a[n - i + 1]);
			Ins(ps[n - i + 1] - 2 * a[1]);
			Ins(ps[n - i + 1]);
		}
		Init();
		Ins(a[1]);
		Ins(-a[1]);
		for (int i = n - 2; i >= 0; i -= 2) {
			long long cur = a[n - i] - (ps[n] - ps[n - i]);
			pair<int, int> P = Split(rt, -cur);
			ans += tr[P.first].sz;
			rt = Merge(P.first, P.second);
			Tag(rt, a[n - i] - a[n - i + 1]);
			Ins(ps[n - i + 1] - 2 * a[1]);
			Ins(ps[n - i + 1]);
		}
		for (int i = 2; i < n; i++) {
			if (ps[n] - ps[i] < ps[i]) ans++;
		}
		ans %= 998244353;
		printf("%lld\n", ans);
	}
	return 0;
}