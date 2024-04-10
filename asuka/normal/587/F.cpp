#include<bits/stdc++.h>
#define int long long
#define N 100015
#define B 80
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
namespace AC {
	int fail[N], tr[N][26], tot;
	int insert(string s) {
		int u = 0;
		for(auto ch : s) {
			if(!tr[u][ch - 'a']) tr[u][ch - 'a'] = ++tot;
			u = tr[u][ch - 'a'];
		}
		return u;
	}
	queue<int> Q;
	void build() {
		rep(i, 0, 25) if(tr[0][i]) Q.push(tr[0][i]);
		while(!Q.empty()) {
			int u = Q.front();
			Q.pop();
			rep(c, 0, 25) {
				if(tr[u][c]) fail[tr[u][c]] = tr[fail[u]][c], Q.push(tr[u][c]);
				else tr[u][c] = tr[fail[u]][c];
			} 
		}
	}
}
using namespace AC;
VI e[N];
int st[N], ed[N], clk, siz[N], pre[N], ans[N];
int n, q, pos[N];
VI big;
string s[N];
vector<pii> qsma[N];
vector<pair<int, pii>> qbig[N];
void dfs0(int u) {
	st[u] = ++clk;
	for(auto v : e[u]) dfs0(v);
	ed[u] = clk;
}
void dfs1(int u) {
	for(auto v : e[u]) {
		dfs1(v);
		siz[u] += siz[v];
	}
}
int D[N];
void add(int p, int v) {for(; p <= clk; p += lowbit(p)) D[p] += v;}
int query(int p) {int res = 0; for(; p; p -= lowbit(p)) res += D[p]; return res;}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	rep(i, 1, n) {
		cin >> s[i];
		pos[i] = insert(s[i]);
	}
	build();
	rep(i, 1, tot) e[fail[i]].pb(i);//, printf("%d %d\n", fail[i], i);
	dfs0(0);
	rep(i, 1, n) {
		if(SZ(s[i]) >= B) big.pb(i);
	}
	rep(i, 1, q) {
		int l, r, k;
		cin >> l >> r >> k;
		if(SZ(s[k]) >= B) qbig[k].pb(mp(i, mp(l, r)));
		else qsma[l - 1].pb(mp(-i, k)), qsma[r].pb(mp(i, k));
	}
	for(auto x : big) {
		int u = 0;
		memset(siz, 0, sizeof siz);
		memset(pre, 0, sizeof pre);
		for(auto ch : s[x]) {
			u = tr[u][ch - 'a'];
			siz[u]++;
		}
		dfs1(0);
		rep(i, 1, n) pre[i] = pre[i - 1] + siz[pos[i]];
		for(auto y : qbig[x]) ans[y.fi] = pre[y.se.se] - pre[y.se.fi - 1];
	}
	rep(i, 1, n) {
		add(st[pos[i]], 1);
		add(ed[pos[i]] + 1, -1);
		for(auto X : qsma[i]) {
			int u = 0, x = X.se, op = abs(X.fi) / X.fi, o = abs(X.fi);
			for(auto ch : s[x]) {
				u = tr[u][ch - 'a'];
				ans[o] += op * query(st[u]);
			}
		}
	}
	rep(i, 1, q) printf("%lld\n", ans[i]);
	return 0;
}