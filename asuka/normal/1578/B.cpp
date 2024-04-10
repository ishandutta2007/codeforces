#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (register int i=(a);i<=(n);i++)
#define per(i,a,n) for (register int i=(n);i>=(a);i--)
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
const int mod = 1e9 + 7;
int k, n, f[66][6];
map<ll, int> g[6], col;
void inc(int &x, int y) {x = (x + y >= mod) ? (x + y - mod) : (x + y);}
int fuck(char s) {
	switch(s) {
		case 'w': return 0;
		case 'y': return 1;
		case 'g': return 2;
		case 'b': return 3;
		case 'r': return 4;
		case 'o': return 5; 
	}
}
vector<ll> node;
char tmp[11];
void init() {
	rep(i, 0, 5) f[0][i] = 1;
	rep(lvl, 0, 59) rep(p, 0, 5) rep(q, 0, 5) rep(r, 0, 5) {
		if(r == (p ^ 1) || r == (q ^ 1) || p == r || q == r) continue;
		inc(f[lvl + 1][r], (ll) f[lvl][p] * f[lvl][q] % mod);
	}
}
ll getlvl(ll x) {
	int res = k;
	while(x) res--, x >>= 1;
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &k);
	scanf("%d", &n);
	rep(i, 1, n) {
		ll x;
		scanf("%lld%s", &x, tmp);
		col[x] = fuck(tmp[0]);
		while(x) {
			node.pb(x);
			x >>= 1;
		}
	}
	sort(all(node));
	node.erase(unique(all(node)), node.end());
	init();
	auto ok = [&](ll x) {
		auto it = lower_bound(all(node), x);
		if(it == node.end() || (*it) != x) return 0;
		return 1;
	};
	// puts("OK");
	// printf("%d\n", SZ(node));
	per(_, 0, SZ(node) - 1) {
		ll x = node[_];
		ll ls = x << 1, rs = x << 1 | 1;
		bool l = ok(ls), r = ok(rs);
		int lvl = getlvl(ls);
		if(lvl < 0) {
			g[col[x]][x] = 1;
			continue;
		}
		int lR, rR;
		if(col.count(x) > 0) {
			lR = rR = col[x];
		} else {
			lR = 0;
			rR = 5;
		}
		rep(p, 0, 5) rep(q, 0, 5) rep(R, lR, rR) {
			if((p ^ 1) == R || (q ^ 1) == R || p == R || q == R) continue;
			int vl = (l ? g[p][ls] : f[lvl][p]),
			    vr = (r ? g[q][rs] : f[lvl][q]);
			inc(g[R][x], (ll) vl * vr % mod);
		}
	}
	int ans = 0;
	if(ok(1)) {
		rep(p, 0, 5) inc(ans, g[p][1]);
	} else {
		rep(p, 0, 5) inc(ans, f[k - 1][p]);
	}
	printf("%d\n", ans);
	return 0;
}