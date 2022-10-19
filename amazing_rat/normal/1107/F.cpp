#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=(9e18);
int n,s,t;
struct node {
	int from,to,fid,tid,ca,flow;
	ll cost;
}; vector<node> g[1010];
int get_other(int a,node e) {
	if (a==e.from) return e.to;
	return e.from;
}
int get_left(int a,node e) {
	if (a==e.from) return e.ca-e.flow;
	return e.flow;
}
void add_edge(int a,int b,int c,ll c2) {
	node e;
	e.from=a; e.to=b; e.ca=c; e.flow=0;
	e.fid=g[a].size(); e.tid=g[b].size(); e.cost=c2;
	g[a].push_back(e);
	e.cost=-c2;
	g[b].push_back(e);
}
void add_flow(int a,node &e,int f) {
	if (a==e.from) e.flow+=f;
	else e.flow-=f;
}
ll dis[1010],h[1010];
node edgeTo[1010];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
bool LPFA() {
	for (int i=1;i<=t;i++)
		dis[i]=INF;
	memset(edgeTo,0,sizeof(edgeTo));
	dis[s]=0; q.push(make_pair(0,s));
	while (!q.empty()) {
		int x=q.top().second;
		if (q.top().first>dis[x]) { q.pop(); continue; }
		q.pop();
		for (int i=0;i<g[x].size();i++) {
			node e=g[x][i];
			int y=get_other(x,e);
			if (get_left(x,e)>0&&dis[x]+e.cost+h[x]-h[y]<dis[y]) {
				dis[y]=dis[x]+e.cost+h[x]-h[y];
				edgeTo[y]=e;
				q.push(make_pair(dis[y],y));
			}
		}
	}
	return dis[t]!=INF;
}
ll maxcost() {
	ll ans=0; int flow;
	memset(h,0,sizeof(h));
	while (LPFA()) {
		for (int i=1;i<=t;i++) h[i]+=dis[i];
		flow=(1e9);
		for (int i=t;i!=s;i=get_other(i,edgeTo[i]))
			flow=min(flow,get_left(get_other(i,edgeTo[i]),edgeTo[i]));
		for (int i=t;i!=s;i=get_other(i,edgeTo[i]))
			add_flow(get_other(i,edgeTo[i]),g[edgeTo[i].from][edgeTo[i].fid],flow),
			add_flow(get_other(i,edgeTo[i]),g[edgeTo[i].to][edgeTo[i].tid],flow);
		ans+=h[t]*flow;
	}
	return ans;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); s=n*2+1,t=s+1;
	int a,b,k;
	for (int i=1;i<=n;i++) {
		read(a); read(b); read(k);
		for (int j=1;j<=n;j++)
			add_edge(i,j+n,1,-max(0LL,a-(ll)min(j-1,k)*b));
		add_edge(s,i,1,0);
		add_edge(i+n,t,1,0);
	}
	printf("%lld\n",-maxcost());
/*	for (int i=1;i<=t;i++) {
		for (int j=0;j<g[i].size();j++)
			if (g[i][j].from==i)
				if (!get_left(i,g[i][j]))
					printf("%d %d\n",g[i][j].from,g[i][j].to);
	}*/
	return 0;
}