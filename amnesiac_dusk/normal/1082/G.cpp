/*
 * 	I believe if I knew where I was going I'd lose my way
 * 	I believe that the words that he told you are not your grave
 * 	I know that we are not the weight of all our memories
 * 	I believe in the things that I am afraid to say
 *
 * 	I believe that today it's okay to be not okay
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
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
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
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

void solve() {
	int n,m,u,v,te;
	cin>>n>>m;
	PushRelabel G(n+m+2);
	fr(i,1,n) {
		cin>>te;
		G.AddEdge(0, i, te);
	}
	int ans=0;
	fr(i,1,m) {
		cin>>u>>v>>te;
		ans+=te;
		G.AddEdge(u, n+i, infl);
		G.AddEdge(v, n+i, infl);
		G.AddEdge(n+i, n+m+1, te);
	}
	cout<<ans-G.GetMaxFlow(0, n+m+1)<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}