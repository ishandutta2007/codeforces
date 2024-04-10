#pragma GCC optimize("unroll-loops", "omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef long long ll;
typedef long double f80;
//#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b, int mod) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

const int INF=1e9;
struct MinimumCostMaximumFlow {
	typedef int Index;
	typedef int Flow;
	typedef double Cost;
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
			if(dist[t]>=0)
				break;
			if(!useSPFA)
				for(Index i=0; i<n; i++)
					potential[i]+=dist[i];

			Flow d=f;
			Cost distt=0;
			for(Index v=t; v!=s;) {
				Index u=prev[v];
				const Edge &e=g[u][prevEdge[v]];
				d=min(d,e.capacity);
				distt+=e.cost;
				v=u;
			}
			if(distt>=0)
				break;
			f-=d;
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

pii pts[405];
void solve() {
	int n=400;
	cin>>n;
	int mi=1;
	fr(i,1,n) {
		cin>>pts[i].fi>>pts[i].se;
		if(pts[i].se>pts[mi].se)
			mi=i;
	}
	MinimumCostMaximumFlow f;
	f.init(2*n+5);
	fr(i,1,n) {
		f.add(2*n+3,2*i+1,2,0);
		f.add(2*i+2,2*n+4,1,0);
	}
	fr(i,1,n) {
		fr(j,1,n)
			if(pts[i].se>pts[j].se)
				f.add(2*i+1, 2*j+2, 1,-2000000+sqrt((pts[i].fi-pts[j].fi)*(pts[i].fi-pts[j].fi)+(pts[i].se-pts[j].se)*(pts[i].se-pts[j].se)));
	}
	auto ans=f.minimumCostMaximumFlow(2*n+3,2*n+4,n-1,1);
	double fans=2000000*(n-1LL)+ans.fi;
	if(fans>=2000000-1) {
		cout<<-1<<endl;
	} else
		cout<<fans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(20);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}