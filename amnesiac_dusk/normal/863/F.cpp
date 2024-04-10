//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
const int INF=1e9+9;
struct MinimumCostMaximumFlow {
  typedef int Index; typedef int Flow; typedef int Cost;
  static const Flow InfCapacity = INF;
  struct Edge {
    Index to; Index rev;
    Flow capacity; Cost cost;
  };
  vector<vector<Edge> > g;
  void init(Index n) { g.assign(n, vector<Edge>()); }
  void add(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
    Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0; e.cost = cost, f.cost = -cost;
    g[i].push_back(e); g[j].push_back(f);
    g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
  }
  void addB(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
    add(i, j, capacity, cost);
    add(j, i, capacity, cost);
  }
  pair<Cost, Flow> minimumCostMaximumFlow(Index s, Index t, Flow f = InfCapacity, bool useSPFA = false) {
    int n = g.size();
    vector<Cost> dist(n); vector<Index> prev(n); vector<Index> prevEdge(n);
    pair<Cost, Flow> total = make_pair(0, 0);
    vector<Cost> potential(n);
    while(f > 0) {
      fill(dist.begin(), dist.end(), INF);
      if(useSPFA || total.second == 0) {
        deque<Index> q;
        q.push_back(s); dist[s] = 0; vector<bool> inqueue(n);
        while(!q.empty()) {
          Index i = q.front(); q.pop_front(); inqueue[i] = false;
          for(Index ei = 0; ei < (Index)g[i].size(); ei ++) {
            const Edge &e = g[i][ei]; Index j = e.to; Cost d = dist[i] + e.cost;
            if(e.capacity > 0 && d < dist[j]) {
              if(!inqueue[j]) {
                inqueue[j] = true;
                q.push_back(j);
              }
              dist[j] = d; prev[j] = i; prevEdge[j] = ei;
            }
          }
        }
      } else {
        vector<bool> vis(n);
        priority_queue<pair<Cost, Index> > q;
        q.push(make_pair(-0, s)); dist[s] = 0;
        while(!q.empty()) {
          Index i = q.top().second; q.pop();
          if(vis[i]) continue;
          vis[i] = true;
          for(Index ei = 0; ei < (Index)g[i].size(); ei ++) {
            const Edge &e = g[i][ei];
            if(e.capacity <= 0) continue;
            Index j = e.to; Cost d = dist[i] + e.cost + potential[i] - potential[j];
            if(dist[j] > d) {
              dist[j] = d; prev[j] = i; prevEdge[j] = ei;
              q.push(make_pair(-d, j));
            }
          }
        }
      }
      if(dist[t] == INF) break;
      if(!useSPFA) for(Index i = 0; i < n; i ++) potential[i] += dist[i];

      Flow d = f; Cost distt = 0;
      for(Index v = t; v != s; ) {
        Index u = prev[v]; const Edge &e = g[u][prevEdge[v]];
        d = min(d, e.capacity); distt += e.cost; v = u;
      }
      f -= d; total.first += d * distt; total.second += d;
      for(Index v = t; v != s; v = prev[v]) {
        Edge &e = g[prev[v]][prevEdge[v]];
        e.capacity -= d; g[e.to][e.rev].capacity += d;
      }
    }
    return total;
  }
};
int ub[51],lb[51];
void solve() {
	int n,q,t,l,r,v;
	cin>>n>>q;
	fr(i,1,n) {
		lb[i]=1;
		ub[i]=n;
	}
	fr(i,1,q) {
		cin>>t>>l>>r>>v;
		if(t==1)
			fr(j,l,r)
				lb[j]=max(lb[j],v);
		else
			fr(j,l,r)
				ub[j]=min(ub[j],v);
	}
	MinimumCostMaximumFlow network;
	network.init(155);
	fr(i,1,n) {
		network.add(0, i, n, 0);
	}
	fr(i,1,n)
		fr(j,1,n)
			network.add(i, n+i, 1, j*j-(j-1)*(j-1));
	fr(i,1,n) {
		fr(j,lb[i],ub[i])
			network.add(n+j, 2*n+i, 1, 0);
		network.add(2*n+i, 3*n+1, 1, 0);
	}
	pii flow=network.minimumCostMaximumFlow(0, 3*n+1);
//	cout<<flow.se<<" "<<flow.fi<<endl;
	if(flow.se==n) {
		cout<<flow.fi<<endl;
	} else
		cout<<-1<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}