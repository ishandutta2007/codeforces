#include<bits/stdc++.h>
#define ll long long
#define N 55
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
namespace MCMF {
	struct edge {
		int to, nxt, cap, cost;
	} e[N * N * 6];
	int S, T, head[N * 2], tot;
	void init() {
		memset(head, -1, sizeof head);
		tot = 1;
	}
	void add(int u, int v, int cap, int cost) {
		e[++tot] = (edge) {v, head[u], cap, cost};
		head[u] = tot;
		e[++tot] = (edge) {u, head[v], 0, -cost};
		head[v] = tot;
	}
	queue<int> Q;
	int dis[N * 2], from[N * 2], flow[N * 2];
	bool inque[N * 2];
	bool SPFA() {
		memset(dis, 0x3f, sizeof dis);
		memset(inque, 0, sizeof inque);
		memset(from, -1, sizeof from);
		memset(flow, 0, sizeof flow);
		Q.push(S);
		dis[S] = 0;
		flow[S] = inf;
		inque[S] = 1;
		while(SZ(Q)) {
			int u = Q.front();
			Q.pop();
			inque[u] = 0;
			for(int i = head[u]; ~i; i = e[i].nxt) {
				int v = e[i].to, cap = e[i].cap, cost = e[i].cost;
				if(cap > 0 && dis[v] > dis[u] + cost) {
					dis[v] = dis[u] + cost;
					flow[v] = min(cap, flow[u]);
					from[v] = i;
					if(!inque[v]) Q.push(v), inque[v] = 1;
				}
			}
		}
		return from[T] != -1;
	}
	int mincost, maxflow;
	void mcmf() {
		while(SPFA()) {
			maxflow += flow[T];
			for(int i = T; i != S; i = e[from[i] ^ 1].to) {
				mincost += flow[T] * e[from[i]].cost;
				e[from[i]].cap -= flow[T];
				e[from[i] ^ 1].cap += flow[T];
			}
		}
	}
}
using namespace MCMF;
int n, q, L[N], R[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &q);
	init();
	rep(i, 1, n) L[i] = 1, R[i] = n;
	rep(i, 1, q) {
		int opt, l, r, v;
		scanf("%d%d%d%d", &opt, &l, &r, &v);
		rep(i, l, r) {
			if(opt == 1) L[i] = max(L[i], v);
			else R[i] = min(R[i], v);
		}
	}
	rep(i, 1, n) if(L[i] > R[i]) {
		puts("-1");
		return 0;
	}
	S = n * 2 + 1; T = n * 2 + 2;
	rep(i, 1, n) {
		rep(_, 1, n) add(S, i, 1, 2 * _ - 1);
		add(i + n, T, 1, 0);
		rep(j, 1, n) if(L[j] <= i && i <= R[j]) add(i, j + n, 1, 0);
	}
	mcmf();
	printf("%d", mincost);
	return 0;
}