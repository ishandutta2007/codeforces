#include<bits/stdc++.h>
#define ll long long
#define N 1100015
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
const int mod = 1e9 + 7;
int n, m, vis[N], tot, ans[N];
VI e[N][10];
void add(int u, int v, int w) {e[u][w].pb(v);}
queue<VI> q;
void bfs() {
	vis[1] = 1;
	ans[1] = 0;
	q.push({1});
	while(!q.empty()) {
		auto U = q.front();
		q.pop();
		rep(w, 0, 9) {
			VI nxt;
			for(auto u : U) {
				for(auto v : e[u][w]) {
					if(!vis[v]) {
						vis[v] = 1;
						ans[v] = ((ll) ans[u] * 10 + w) % mod;
						nxt.pb(v);
					}
				}
			}
			if(SZ(nxt) > 0) q.push(nxt);
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	tot = n;
	rep(i, 1, m) {
		int u, v, x = i;
		VI cur;
		scanf("%d%d", &u, &v);
		while(x) cur.pb(x % 10), x /= 10;
		reverse(all(cur));
		int lst = u;
		rep(i, 0, SZ(cur) - 1) {
			add(lst, i == SZ(cur) - 1 ? v : ++tot, cur[i]);
			lst = tot;
		}
		lst = v;
		rep(i, 0, SZ(cur) - 1) {
			add(lst, i == SZ(cur) - 1 ? u : ++tot, cur[i]);
			lst = tot;
		} 
	}
	bfs();
	rep(i, 2, n) printf("%d\n", ans[i]);
	return 0;
}