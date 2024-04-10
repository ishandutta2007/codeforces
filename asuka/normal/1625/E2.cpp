#include<bits/stdc++.h>
#include<bits/extc++.h>
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
using namespace __gnu_pbds;
using Tree = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>; 
const int N = 300015;
int n, q, match[N], st[N], ed[N], pa[N], id[N], tot, clk, sons[N];
Tree T[N];
char s[N];
void build(int l, int r, int fa) {
	if (l > r) return;
	if (!match[l]) return build(l + 1, r, fa);
	if (!match[r]) return build(l, r - 1, fa);
	id[l] = id[match[l]] = ++tot;
	st[id[l]] = ++clk; pa[id[l]] = fa; sons[fa]++; T[fa].insert(id[l]);
	build(l + 1, match[l] - 1, id[l]);
	ed[id[l]] = clk;
	build(match[l] + 1, r, fa);
}
ll D[N];
void add(int p, ll v) {for (; p <= clk; p += lowbit(p)) D[p] += v;}
ll query(int p) {ll res = 0; for (; p; p -= lowbit(p)) res += D[p]; return res;}
ll query(int l, int r) {return query(r) - query(l - 1);}
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	VI stk;
	rep(i, 1, n) {
		if (s[i] == '(') stk.pb(i);
		else {
			if (SZ(stk) > 0) {
				match[stk.back()] = i;
				stk.pop_back();
			}
		}
	}
	build(1, n, 0);
#define F(x) ((ll) (x) * (x - 1) / 2)
	rep(i, 1, tot) add(st[i], F(sons[i]) + 1);
	rep(_, 1, q) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		int f = pa[id[l]];
		if (t == 1) {
			add(st[id[l]], -1);
			T[f].erase(id[l]);
			if (f) add(st[f], F(sons[f] - 1) - F(sons[f])), sons[f]--;
		} else {
			printf("%lld\n", query(st[id[l]], ed[id[r]]) + F(T[f].order_of_key(id[r] + 1) - T[f].order_of_key(id[l])));
		}
	}
	return 0;
}