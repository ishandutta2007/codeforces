#include<bits/stdc++.h>
#define ll long long
#define N 15000
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
		int to, cap, nxt;
		ll cost;
		edge(){}
		edge(int a, int b, ll c, int d) {to = a; cap = b; cost = c; nxt = d;}
	} e[N << 2];
	int head[N], tot = 1;
	void init() {
		memset(head, -1, sizeof head);
	}
	void add(int u, int v, int cap, ll cost) {
		e[++tot] = edge(v, cap, cost, head[u]);
		head[u] = tot;
		e[++tot] = edge(u, 0, -cost, head[v]);
		head[v] = tot;
	}
	int S, T;
	int from[N], flow[N];
	ll mincost, maxflow, dis[N], h[N];
	bool vis[N];
	queue<int> q;
	bool SPFA() {
		memset(dis, 0x3f, sizeof dis);
		memset(from, -1, sizeof from);
		memset(vis, 0, sizeof vis);
		dis[S] = 0;
		flow[S] = inf;
		vis[S] = 1;
		q.push(S);
		while(!q.empty()) {
			int u = q.front();
			vis[u] = 0;
			q.pop();
			for(int i = head[u]; ~i; i = e[i].nxt) {
				int v = e[i].to, cap = e[i].cap, cost = e[i].cost;
				if(cap > 0 && dis[v] > dis[u] + cost) {
					from[v] = i;
					flow[v] = min(flow[u], cap);
					dis[v] = dis[u] + cost;
					if(!vis[v]) q.push(v), vis[v] = 1;
				}
			}
		}
		return from[T] != -1;
	}
	void mcmf() {
		while(SPFA()) {
			maxflow += flow[T];
			for(int i = T; i != S; i = e[from[i] ^ 1].to) {
				mincost += (ll) flow[T] * e[from[i]].cost;
				e[from[i]].cap -= flow[T];
				e[from[i] ^ 1].cap += flow[T];
			}
		}
	}
};
using namespace MCMF;
int n, a[N], in[N], out[N], lst[100015], l7[7], cnt;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	init();
	rep(i, 1, n) {
		in[i] = ++cnt;
		out[i] = ++cnt;
		add(in[i], out[i], 1, -1);
	}
	rep(i, 1, n) scanf("%d", &a[i]);
	per(i, 1, n) {
		// +/- 1
		if(lst[a[i] + 1]) add(out[i], lst[a[i] + 1], inf, 0);
		if(lst[a[i] - 1]) add(out[i], lst[a[i] - 1], inf, 0);
		// % 7
		if(l7[a[i] % 7]) add(out[i], l7[a[i] % 7], inf, 0);
		cnt++;
		add(cnt, in[i], inf, 0);
		if(lst[a[i]]) add(cnt, lst[a[i]], inf, 0);
		lst[a[i]] = cnt;
		cnt++;
		add(cnt, in[i], inf, 0);
		if(l7[a[i] % 7]) add(cnt, l7[a[i] % 7], inf, 0);
		l7[a[i] % 7] = cnt;
	}
	S = ++cnt;
	T = ++cnt;
	rep(i, 1, n) add(S, in[i], inf, 0);
	cnt++;
	add(cnt, T, 4, 0);
	rep(i, 1, n) add(out[i], cnt, inf, 0);
	mcmf();
	printf("%lld\n", -mincost);
	return 0;
}