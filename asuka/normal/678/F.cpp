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

const int N = 300015, M = N * 31;

#define mid (l + ((r - l + 1) >> 1) - 1)
#define lch ls[p], l, mid
#define rch rs[p], mid + 1, r
struct line {
	int k, b;
	ll calc(int x) {return (ll) k * x + b;}
} q[N];

int t[M], ls[M], rs[M], tot, rt, trash[M >> 1], stk[M >> 1], tra, top;

int* stk2[M >> 1];

void add(int &p, int l, int r, int x) {
	if (!p) {
		if (tra == 0) p = ++tot;
		else p = trash[tra--];

		t[p] = x;
		top++;
		stk[top] = -1; stk2[top] = &p;
		return;
	}

	if (q[x].calc(mid) > q[t[p]].calc(mid)) {
		top++;
		stk[top] = t[p]; stk2[top] = &p;
		swap(x, t[p]);
	}

	if (l == r) return;

	if (q[x].k < q[t[p]].k) add(lch, x);
	else add(rch, x);
}

ll ask(int p, int l, int r, int pos) {
	if (!p) return -infll;

	ll ans = q[t[p]].calc(pos);

	if (l == r) return ans;

	ans = max(ans, pos <= mid ? ask(lch, pos) : ask(rch, pos));

	return ans;
}

int n, las[N];

vector<int> tr[N << 2], que[N];

void ins(int p, int l, int r, int x, int y, int v) {
	if (x <= l && r <= y) return tr[p].pb(v), void();

	if (x <= mid) ins(p << 1, l, mid, x, y, v);

	if (y > mid) ins(p << 1 | 1, mid + 1, r, x, y, v);
}

void dfs(int p, int l, int r) {
	int cur = top;

	for (int x : tr[p]) add(rt, -1e9, 1e9, x);

	if (l == r) {
		for (int x : que[l]) {
			ll o = ask(rt, -1e9, 1e9, x);

			if (o == -infll) puts("EMPTY SET");
			else printf("%lld\n", o);
		}

	} else dfs(p << 1, l, mid), dfs(p << 1 | 1, mid + 1, r);

	while (top > cur) {
		int *x = stk2[top], y = stk[top--];

		if (y == -1) trash[++tra] = *x, *x = 0;
		else t[*x] = y;
	}
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);
	rep(i, 1, n) {
		int t, x, y;
		las[i] = -1;
		scanf("%d%d", &t, &x);

		if (t == 1) {
			scanf("%d", &y);
			q[i] = (line) {x, y};
			las[i] = 0;

		} else if (t == 2) {
			las[x] = i;

		} else que[i].pb(x);
	}

	rep(i, 1, n) if (~las[i]) ins(1, 1, n, i, las[i] == 0 ? n : las[i], i);

	dfs(1, 1, n);
	return 0;
}