#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef float f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
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
typedef vector<ll> vl;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};
struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<ll> excess;
  vector<int> dist, active, count;
  queue<int> Q;
  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}
  void AddEdge(int from, int to, int cap){
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if(from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1)); // for bidirectional set cap.
  }
  void Enqueue(int v){
    if(!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
  }
  void Push(Edge &e){
    int amt = min(excess[e.from], ll(e.cap - e.flow));
    if(dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  void Gap(int k){
    fr(v, 0, N - 1){
      if(dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N + 1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }
  void Relabel(int v){
    count[dist[v]]--;
    dist[v] = 2 * N;
    fr(i, 0, G[v].size() - 1)
      if(G[v][i].cap - G[v][i].flow > 0)
        dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }
  void Discharge(int v){
    for(int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if(excess[v] > 0){
      if(count[dist[v]] == 1) Gap(dist[v]);
      else Relabel(v);
    }
  }
  ll GetMaxFlow(int s, int t) {
    count[0] = N - 1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = 1;
    fr(i, 0, (int)G[s].size() - 1){
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    while(!Q.empty()){
      int v = Q.front();
      Q.pop();
      active[v] = 0;
      Discharge(v);
    }
    ll totflow = 0;
    fr(i, 0, (int)G[s].size() - 1) totflow += G[s][i].flow;
    return totflow;
  }
};

int rects[51][4];
void solve() {
	int n,m;
	cin>>n>>m;
	vector<int> cx,cy;
	fr(i,1,m) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		rects[i][0]=x1;
		rects[i][1]=x2;
		rects[i][2]=y1;
		rects[i][3]=y2;
		cx.pb(x1);
		cx.pb(x2);
		cx.pb(x1-1);
		cx.pb(x2-1);
		cy.pb(y1);
		cy.pb(y2);
		cy.pb(y1-1);
		cy.pb(y2-1);
	}
	sort(all(cx));
	sort(all(cy));
	cx.resize(unique(all(cx))-cx.begin());
	cy.resize(unique(all(cy))-cy.begin());
	PushRelabel hol(cx.size()+cy.size()+5);
	int src=sz(cx)+sz(cy)+1,dest=sz(cx)+sz(cy)+2;
	for(int i=1; i<cx.size(); i++)
		hol.AddEdge(src, i, cx[i]-cx[i-1]);
	for(int i=1; i<cy.size(); i++)
		hol.AddEdge(sz(cx)+i,dest, cy[i]-cy[i-1]);
	for(int i=1; i<=m; i++)
		for(int j=1; j<sz(cx); j++)
			for(int k=1; k<sz(cy); k++)
				if(cx[j-1]>=rects[i][0]-1&&cx[j]<=rects[i][1])
					if(cy[k-1]>=rects[i][2]-1&&cy[k]<=rects[i][3])
						hol.AddEdge(j, sz(cx)+k, infi);
	cout<<hol.GetMaxFlow(src, dest);
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
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