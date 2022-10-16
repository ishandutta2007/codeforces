#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

vi lol;
const int INF=1e9;
struct MinimumCostMaximumFlow {
	typedef int Index;
	typedef int Flow;
	typedef int Cost;
	static const Flow InfCapacity=INF;
	struct Edge {
		Index to;
		Index rev;
		Flow capacity;
		Cost cost;
	};
	vector<vector<Edge> > g;
	void init(Index n) {
		g.assign(n,vector<Edge>());
	}
	void add(Index i, Index j, Flow capacity=InfCapacity, Cost cost=Cost()) {
		Edge e,f;
		e.to=j,f.to=i;
		e.capacity=capacity,f.capacity=0;
		e.cost=cost,f.cost=-cost;
		g[i].push_back(e);
		g[j].push_back(f);
		g[i].back().rev=(Index)g[j].size()-1;
		g[j].back().rev=(Index)g[i].size()-1;
	}
	void addB(Index i, Index j, Flow capacity=InfCapacity, Cost cost=Cost()) {
		add(i,j,capacity,cost);
		add(j,i,capacity,cost);
	}
	pair<Cost, Flow> minimumCostMaximumFlow(Index s, Index t, Flow f=InfCapacity, bool useSPFA=false) {
		int n=g.size();
		vector<Cost> dist(n);
		vector<Index> prev(n);
		vector<Index> prevEdge(n);
		pair<Cost, Flow> total=make_pair(0,0);
		vector<Cost> potential(n);
		while(f>0) {
			fill(dist.begin(),dist.end(),INF);
			if(useSPFA||total.second==0) {
				deque<Index> q;
				q.push_back(s);
				dist[s]=0;
				vector<bool> inqueue(n);
				while(!q.empty()) {
					Index i=q.front();
					q.pop_front();
					inqueue[i]=false;
					for(Index ei=0; ei<(Index)g[i].size(); ei++) {
						const Edge &e=g[i][ei];
						Index j=e.to;
						Cost d=dist[i]+e.cost;
						if(e.capacity>0&&d<dist[j]) {
							if(!inqueue[j]) {
								inqueue[j]=true;
								q.push_back(j);
							}
							dist[j]=d;
							prev[j]=i;
							prevEdge[j]=ei;
						}
					}
				}
			} else {
				vector<bool> vis(n);
				priority_queue<pair<Cost, Index> > q;
				q.push(make_pair(-0,s));
				dist[s]=0;
				while(!q.empty()) {
					Index i=q.top().second;
					q.pop();
					if(vis[i])
						continue;
					vis[i]=true;
					for(Index ei=0; ei<(Index)g[i].size(); ei++) {
						const Edge &e=g[i][ei];
						if(e.capacity<=0)
							continue;
						Index j=e.to;
						Cost d=dist[i]+e.cost+potential[i]-potential[j];
						if(dist[j]>d) {
							dist[j]=d;
							prev[j]=i;
							prevEdge[j]=ei;
							q.push(make_pair(-d,j));
						}
					}
				}
			}
			if(dist[t]==INF)
				break;
			if(!useSPFA)
				for(Index i=0; i<n; i++)
					potential[i]+=dist[i];

			Flow d=1;
			Cost distt=0;
			for(Index v=t; v!=s;) {
				Index u=prev[v];
				const Edge &e=g[u][prevEdge[v]];
				d=min(d,e.capacity);
				distt+=e.cost;
				v=u;
			}
			f-=d;
			lol.pb(distt);
			total.first+=d*distt;
			total.second+=d;
			for(Index v=t; v!=s; v=prev[v]) {
				Edge &e=g[prev[v]][prevEdge[v]];
				e.capacity-=d;
				g[e.to][e.rev].capacity+=d;
			}
		}
		return total;
	}
};

void solve() {
	int n,m;
	cin>>n>>m;
	MinimumCostMaximumFlow G;
	G.init(n+1);
	fr(i,1,m) {
		int u,v,w;
		cin>>u>>v>>w;
		G.add(u,v,1,w);
	}
	G.minimumCostMaximumFlow(1, n,MinimumCostMaximumFlow::InfCapacity,1);
	vi dif;
	dif.pb(0);
	for(int i=1; i<sz(lol); i++)
		dif.pb((lol[i]-lol[i-1])*i);
	for(int i=1; i<sz(dif); i++)
		dif[i]+=dif[i-1];
	int q;
	cin>>q;
	while(q--) {
		int xi;
		cin>>xi;
		int ind=upper_bound(all(dif),xi)-dif.begin()-1;
		int tol=xi-dif[ind];
		cout<<lol[ind]+tol/(ind+1.0L)<<endl;
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
}