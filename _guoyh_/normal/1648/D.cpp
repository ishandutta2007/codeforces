# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;
# define fi first
# define se second
const int MAXN = 500051;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, q;
struct SegTree{
	struct Node{
		ll s;
		int ls, rs;
	} t[MAXN * 4];
	int rt, tsz;
	void update(int nw){
		t[nw].s = max(t[t[nw].ls].s, t[t[nw].rs].s);
	}
	void build(int &nw, int lft, int rgt){
		nw = ++tsz;
		if (lft == rgt){
			t[nw].s = -INF;
			return;
		}
		int mid = (lft + rgt) >> 1;
		build(t[nw].ls, lft, mid);
		build(t[nw].rs, mid + 1, rgt);
	}
	void modify(int nw, int lft, int rgt, int pos, ll nm){
		if (lft == rgt){
			t[nw].s = nm;
			return;
		}
		int mid = (lft + rgt) >> 1;
		if (pos <= mid) modify(t[nw].ls, lft, mid, pos, nm);
		else modify(t[nw].rs, mid + 1, rgt, pos, nm);
		update(nw);
	}
	ll getsum(int nw, int lft, int rgt, int l, int r){
		if (lft == l && rgt == r) return t[nw].s;
		int mid = (lft + rgt) >> 1;
		if (r <= mid) return getsum(t[nw].ls, lft, mid, l, r);
		else if (l >= mid + 1) return getsum(t[nw].rs, mid + 1, rgt, l, r);
		else return max(getsum(t[nw].ls, lft, mid, l, mid), getsum(t[nw].rs, mid + 1, rgt, mid + 1, r));
	}
} sg1;
struct Dat{
	ll s1, s2, ss;
	Dat(ll s1 = -INF, ll s2 = -INF, ll ss = -INF): s1(s1), s2(s2), ss(ss){}
};
Dat operator + (const Dat &u, const Dat &v){
	return Dat(max(u.s1, v.s1), max(u.s2, v.s2), max(u.s1 + v.s2, max(u.ss, v.ss)));
}
ll a1[MAXN], a2[MAXN], a3[MAXN];
ll s1[MAXN], s2[MAXN], s3[MAXN];
ll f[MAXN];
vector <pll> adj[MAXN];
struct SegTree1{
	struct Node{
		Dat s;
		int ls, rs;
	} t[MAXN * 4];
	int rt, tsz;
	void update(int nw){
		t[nw].s = t[t[nw].ls].s + t[t[nw].rs].s;
	}
	void build(int &nw, int lft, int rgt){
		nw = ++tsz;
		if (lft == rgt){
			t[nw].s = Dat(f[lft], s3[n] - s3[lft - 1] + s2[lft], f[lft] + s3[n] - s3[lft - 1] + s2[lft]);
			return;
		}
		int mid = (lft + rgt) >> 1;
		build(t[nw].ls, lft, mid);
		build(t[nw].rs, mid + 1, rgt);
		update(nw);
	}
	Dat getsum(int nw, int lft, int rgt, int l, int r){
		if (lft == l && rgt == r) return t[nw].s;
		int mid = (lft + rgt) >> 1;
		if (r <= mid) return getsum(t[nw].ls, lft, mid, l, r);
		else if (l >= mid + 1) return getsum(t[nw].rs, mid + 1, rgt, l, r);
		else return getsum(t[nw].ls, lft, mid, l, mid) + getsum(t[nw].rs, mid + 1, rgt, mid + 1, r);
	}
} sg2;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a1[i];
		s1[i] = s1[i - 1] + a1[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> a2[i];
		s2[i] = s2[i - 1] + a2[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> a3[i];
		s3[i] = s3[i - 1] + a3[i];
	}
	for (int i = 1; i <= q; i++){
		int l, r, k;
		cin >> l >> r >> k;
		adj[r].push_back(pll(l, k));
	}
	sg1.build(sg1.rt, 1, n);
	for (int i = 1; i <= n; i++){
		f[i] = s1[i] - s2[i - 1];
		for (int j = 0; j < adj[i - 1].size(); j++){
			f[i] = max(f[i], sg1.getsum(sg1.rt, 1, n, adj[i - 1][j].fi, i - 1) - adj[i - 1][j].se);
		}
		// cout << "f " << i << ' ' << f[i] << '\n';
		sg1.modify(sg1.rt, 1, n, i, f[i]);
	}
	ll ans = -INF;
	sg2.build(sg2.rt, 1, n);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < adj[i].size(); j++){
			ans = max(ans, sg2.getsum(sg2.rt, 1, n, adj[i][j].fi, i).ss - adj[i][j].se);
		}
	}
	cout << ans << '\n';
	return 0;
}