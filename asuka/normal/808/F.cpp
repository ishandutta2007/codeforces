#include<bits/stdc++.h>
#define ll long long
#define N 105
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
namespace Dinic {
	struct edge {
		int to, nxt, cap;
	} e[N * N];
	int tot, dep[N], head[N], cur[N], S, T;
	void init() {
		tot = 1;
		memset(head, -1, sizeof head);
	}
	void add(int u, int v, int cap) {
		e[++tot] = (edge){v, head[u], cap};
		head[u] = tot;
		e[++tot] = (edge){u, head[v], 0};
		head[v] = tot;
	}
	queue<int> q;
	bool bfs() {
		memset(dep, -1, sizeof dep);
		q.push(S);
		dep[S] = 0;
		cur[S] = head[S];
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i = head[u]; ~i; i = e[i].nxt) {
				int v = e[i].to, cap = e[i].cap;
				if(cap > 0 && dep[v] == -1) {
					dep[v] = dep[u] + 1;
					cur[v] = head[v];
					q.push(v);
				} 
			}
		}
		return dep[T] != -1;
	}
	int dfs(int u, int dis) {
		if(u == T || dis == 0) return dis;
		int flow = 0;
		for(int i = cur[u]; ~i; i = e[i].nxt) {
			cur[u] = i;
			int v = e[i].to, cap = e[i].cap;
			if(dep[v] == dep[u] + 1 && cap > 0) {
				int f = dfs(v, min(dis, cap));
				if(f) {
					e[i].cap -= f;
					e[i ^ 1].cap += f;
					dis -= f;
					flow += f;
					if(!dis) break;
				}
			}
		}
		return flow;
	}
	int dinic() {
		int ans = 0;
		while(bfs()) {
			ans += dfs(S, inf);
		}
		return ans;
	}
}
using namespace Dinic;

int tt, pri[200015], notp[200015];
void getPri() {
	rep(i, 2, 200000) {
		if(!notp[i]) pri[++tt] = i;
		for(int j = 1; j <= tt && pri[j] * i <= 200000; ++j) {
			notp[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

int n, k, p[N], c[N], l[N];
bool check(int x) {
	int Maxp = -1;
	vector<pii> Odd, Even;
	rep(i, 1, n) {
		if(l[i] > x) continue;
		if(c[i] == 1) {
			Maxp = max(Maxp, p[i]);
			continue;
		}
		if(c[i] & 1) Odd.pb(mp(p[i], c[i]));
		else Even.pb(mp(p[i], c[i]));
	}
	if(Maxp != -1) Odd.pb(mp(Maxp, 1));
	init();
	S = SZ(Odd) + SZ(Even) + 1;
	T = SZ(Odd) + SZ(Even) + 2;
	int sum = 0;
	rep(i, 0, SZ(Odd) - 1) add(S, i + 1, Odd[i].fi), sum += Odd[i].fi;
	rep(i, 0, SZ(Even) - 1) add(i + SZ(Odd) + 1, T, Even[i].fi), sum += Even[i].fi;
	rep(i, 0, SZ(Odd) - 1) {
		rep(j, 0, SZ(Even) - 1) {
			if(!notp[Odd[i].se + Even[j].se]) {
				add(i + 1, j + SZ(Odd) + 1, inf);
			}
		}
	}
	int res = dinic();
	sum -= res;
	return sum >= k;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	getPri();
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d%d%d", &p[i], &c[i], &l[i]);
	int L = 1, R = n, ans = -1;
	while(L <= R) {
		int mid = (L + R) >> 1;
		if(check(mid)) ans = mid, R = mid - 1;
		else L = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}