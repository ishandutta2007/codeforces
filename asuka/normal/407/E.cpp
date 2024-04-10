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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 200015;
namespace seg {
#define ls (p << 1)
#define rs (p << 1 | 1)
ll T[N << 2], tag[N << 2];
int n, k, d, a[N], L[N];
void pushup(int p) {T[p] = min(T[ls], T[rs]);}
void build(int p, int l, int r) {
	T[p] = infll;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}
void down(int p, ll v) {
	T[p] += v;
	tag[p] += v;
}
void pushdown(int p) {
	if (tag[p] != 0) down(ls, tag[p]), down(rs, tag[p]);
	tag[p] = 0;
}
void add(int p, int l, int r, int x, int y, ll v) {
	if (x <= l && r <= y) {
		down(p, v);
		return;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if (x <= mid) add(ls, l, mid, x, y, v);
	if (y > mid) add(rs, mid + 1, r, x, y, v);
	pushup(p);
}
void modify(int p, int l, int r, int pos, ll val) {
	if (l == r) {
		T[p] = val + pos;
		return;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if (pos <= mid) modify(ls, l, mid, pos, val);
	else modify(rs, mid + 1, r, pos, val);
	pushup(p);
}
int query(int p, int l, int r, int k) {
	if (T[p] > k) return n + 1;
	if (l == r) return l;
	pushdown(p);
	int mid = (l + r) >> 1;
	if (T[ls] <= k) return query(ls, l, mid, k);
	return query(rs, mid + 1, r, k);
}
}
using namespace seg;
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &k, &d);
	rep(i, 1, n) scanf("%d", &a[i]), a[i] += 1e9;
	if (d == 0) {
		int al = 1, ar = 1;
		for (int l = 1, r; l <= n; l = r + 1) {
			r = l;
			while (r < n && a[r + 1] == a[l]) r++;
			if (r - l + 1 > ar - al + 1) ar = r, al = l;
		}
		printf("%d %d\n", al, ar);
		return 0;
	}
	for (int l = 1, r; l <= n; l = r + 1) {
		r = l;
		int o = a[l] % d;
		while (r < n && a[r + 1] % d == o) r++;
		rep(i, l, r) {
			L[i] = l;
			a[i] = (a[i] - o) / d;
		}
	}
	vector<array<int, 3>> Max, Min;
	map<int, int> cnt;
	int ptr = 1, al = 1, ar = 1;
	build(1, 1, n);
	rep(i, 1, n) {
		modify(1, 1, n, i, 0);
		cnt[a[i]]++;
		while (ptr < L[i] || cnt[a[i]] > 1) cnt[a[ptr]]--, modify(1, 1, n, ptr, infll), ptr++;
		while (SZ(Max) && Max.back()[2] <= a[i]) {
			add(1, 1, n, Max.back()[0], Max.back()[1], a[i] - Max.back()[2]);
			Max.pop_back();
		}
		Max.push_back({SZ(Max) > 0 ? Max.back()[1] + 1 : 1, i, a[i]});
		while (SZ(Min) && Min.back()[2] >= a[i]) {
			add(1, 1, n, Min.back()[0], Min.back()[1], Min.back()[2] - a[i]);
			Min.pop_back();
		}
		Min.push_back({SZ(Min) > 0 ? Min.back()[1] + 1 : 1, i, a[i]});
		int le = query(1, 1, n, i + k); // smallest l such that Max_l - Min_l + l <= i + k
		if (i - le + 1 > ar - al + 1) ar = i, al = le;
	}
	printf("%d %d\n", al, ar);
	return 0;
}