#include<bits/stdc++.h>
#define ll long long
#define N 755
#define L 10000015
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
int n;
bool conn[N][N];
int match[N];
bool ok[N], vis[N], used[N][2];
string s[N];
void dfs2(int u, int typ) {
	if(used[u][typ]) return;
	used[u][typ] = 1;
	rep(v, 1, n) {
		if(!(typ ? conn[v][u] : conn[u][v])) continue;
		if((typ ? match[u] == v : match[v] != u)) {
			dfs2(v, typ ^ 1);
		}
	}
}
bool dfs(int u) {
	rep(v, 1, n) {
		if(vis[v] || !conn[u][v]) continue;
		vis[v] = 1;
		if(!match[v] || dfs(match[v])) {
			match[v] = u;
			return 1;
		}
	}
	return 0;
}
void solve() {
	rep(i, 1, n) {
		memset(vis, 0, sizeof vis);
		dfs(i);
	}
	rep(i, 1, n) ok[match[i]] = 1; 
}
namespace AC {
	VI ord;
	int tr[L][2], tot, fail[L], lst[L], end[L];
	void insert(string s, int id) {
		int u = 0;
		for(auto ch : s) {
			if(!tr[u][ch - 'a']) tr[u][ch - 'a'] = ++tot;
			u = tr[u][ch - 'a'];
		}
		end[u] = id;
	}
	queue<int> q;
	void build() {
		rep(i, 0, 1) if(tr[0][i]) q.push(tr[0][i]);
		while(SZ(q)) {
			int u = q.front();
			q.pop();
			ord.pb(u);
			rep(i, 0, 1) {
				if(tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
				else tr[u][i] = tr[fail[u]][i];
			}
		}
	}
	void getlst() {
		for(auto x : ord) lst[x] = end[x] ? end[x] : lst[fail[x]];
	}
	void travel(string s, int id) {
		int u = 0;
		for(auto ch : s) {
			u = tr[u][ch - 'a'];
			if(lst[u] != id) conn[id][lst[u]] = 1;
			else conn[id][lst[fail[u]]] = 1;
		}
	}
}
using namespace AC;
bool issubstr(string a, string b) {
	if(SZ(a) < SZ(b)) swap(a, b);
	rep(i, 0, SZ(a) - SZ(b)) if(a.substr(i, SZ(b)) == b) return 1;
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> s[i], insert(s[i], i);
	build();
	getlst();
	rep(i, 1, n) travel(s[i], i);
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) conn[i][j] |= conn[i][k] & conn[k][j];
	solve();
	rep(i, 1, n) if(!ok[i]) dfs2(i, 0);
	VI res;
	rep(i, 1, n) if(used[i][0] && !used[i][1]) res.pb(i);
	cout << SZ(res) << endl;
	for(auto x : res) cout << x << ' ';
	return 0;
}