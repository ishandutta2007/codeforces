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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
using namespace std;
const int N = 100015, B = 317;
struct query {
	int l, r, id;
	bool operator <(const query &rhs) const {
		if (l / B != rhs.l / B) return l / B < rhs.l / B;
		return r / B < rhs.r / B;
	}
} q[N];
int n, m, b[N], lst[N], pre[N], nxt[N], len[N], f[N], res[N], ans = 0;

int buc[N], cnt[N], has[B + B];
void Add(int x) {
	if (buc[x]++ == 0) has[x / B]++;
}
void Del(int x) {
	if (--buc[x] == 0) has[x / B]--;
}
int getMin() {
	rep(i, 0, B) if (has[i]) {
		rep(j, i * B, (i + 1) * B - 1) {
			if (buc[j] > 0) return j;
		}
	}
	return n + 1;
}
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &b[i]);
	rep(i, 1, n) {
		pre[i] = lst[b[i]];
		len[i] = pre[i] ? i - pre[i] : -1;
		lst[b[i]] = i;
	}
	memset(lst, 0, sizeof lst);
	per(i, 1, n) {
		nxt[i] = lst[b[i]] == 0 ? n + 1 : lst[b[i]];
		lst[b[i]] = i;
	}
	rep(i, 1, n) {
		if (!pre[i]) f[i] = 0;
		else {
			if (len[pre[i]] == -1) f[i] = 0;
			else if (len[i] == len[pre[i]]) f[i] = f[pre[i]];
			else f[i] = pre[pre[i]] + 1;
		}
	}
	scanf("%d", &m);
	rep(i, 1, m) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
	sort(q + 1, q + m + 1);
	for (int i = 1, l = 1, r = 0; i <= m; ++i) {
		auto add = [&](int x) {
			if (cnt[b[x]]++ == 0) ans++;
			if (nxt[x] > r) {
				Add(f[x]);
				if (pre[x] >= l) Del(f[pre[x]]);
			}
		};
		auto del = [&](int x) {
			if (--cnt[b[x]] == 0) ans--;
			if (nxt[x] > r) {
				Del(f[x]);
				if (pre[x] >= l) Add(f[pre[x]]);
			}
		};
		while (l > q[i].l) add(--l);
		while (r < q[i].r) add(++r);
		while (l < q[i].l) del(l++);
		while (r > q[i].r) del(r--);
		res[q[i].id] = ans + (getMin() > l);
	}
	rep(i, 1, m) printf("%d\n", res[i]);
	return 0;
}