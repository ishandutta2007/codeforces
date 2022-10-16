/*
 * 	In an empty-like sky
 * 		What were you looking at?
 * 			I did not even understand
 * 				The reason I woke up
 * 	I was terribly scared
 * 		Of believing
 * 			Because of that
 * 				I've thrown everything away
 * 	It would have been better
 * 		If this world that I hate so much
 * 			Could just disappear
 * 				If I continue to believe
 * 					Won't it hurt me?
 *
 * 	It was your voice
 * 		That has saved me
 * 			And keeps me going
 * 				The feeling that you taught me
 * 					That's true.
 * 	I will scream your name
 * 		Strongly hold your hand
 * 			I will not let go of it anymore
 * 				No matter what the future holds
 * 					If you're with me, I won't run away
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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

struct Edge {
	int from,to,cap,flow,index;
	Edge(int from, int to, int cap, int flow, int index) :
			from(from), to(to), cap(cap), flow(flow), index(index) {
	}
};
struct PushRelabel {
	int N;
	vector<vector<Edge> > G;
	vector<ll> excess;
	vector<int> dist,active,count;
	queue<int> Q;
	PushRelabel(int N) :
			N(N), G(N), excess(N), dist(N), active(N), count(2*N) {
	}
	void AddEdge(int from, int to, int cap) {
		G[from].push_back(Edge(from,to,cap,0,G[to].size()));
		if(from==to)
			G[from].back().index++;
		G[to].push_back(Edge(to,from,0,0,G[from].size()-1)); // for bidirectional set cap.
	}
	void Enqueue(int v) {
		if(!active[v]&&excess[v]>0) {
			active[v]=true;
			Q.push(v);
		}
	}
	void Push(Edge &e) {
		int amt=min(excess[e.from],ll(e.cap-e.flow));
		if(dist[e.from]<=dist[e.to]||amt==0)
			return;
		e.flow+=amt;
		G[e.to][e.index].flow-=amt;
		excess[e.to]+=amt;
		excess[e.from]-=amt;
		Enqueue(e.to);
	}
	void Gap(int k) {
		fr(v, 0, N - 1)
		{
			if(dist[v]<k)
				continue;
			count[dist[v]]--;
			dist[v]=max(dist[v],N+1);
			count[dist[v]]++;
			Enqueue(v);
		}
	}
	void Relabel(int v) {
		count[dist[v]]--;
		dist[v]=2*N;
		fr(i, 0, G[v].size() - 1)
			if(G[v][i].cap-G[v][i].flow>0)
				dist[v]=min(dist[v],dist[G[v][i].to]+1);
		count[dist[v]]++;
		Enqueue(v);
	}
	void Discharge(int v) {
		for(int i=0; excess[v]>0&&i<G[v].size(); i++)
			Push(G[v][i]);
		if(excess[v]>0) {
			if(count[dist[v]]==1)
				Gap(dist[v]);
			else
				Relabel(v);
		}
	}
	ll GetMaxFlow(int s, int t) {
		count[0]=N-1;
		count[N]=1;
		dist[s]=N;
		active[s]=active[t]=1;
		fr(i, 0, (int)G[s].size() - 1)
		{
			excess[s]+=G[s][i].cap;
			Push(G[s][i]);
		}
		while(!Q.empty()) {
			int v=Q.front();
			Q.pop();
			active[v]=0;
			Discharge(v);
		}
		ll totflow=0;
		fr(i, 0, (int)G[s].size() - 1)
			totflow+=G[s][i].flow;
		return totflow;
	}
};
int n,k;
int pcl[105][3];
vector<bool> primes(200005,1);
map<int,int> primalvalues,numtoindex;
int check(int level) {
	vector<int> odd,even;
	int one=0;
	trace(one);
	primalvalues.clear();
	numtoindex.clear();
	fr(i,1,n) {
		if(pcl[i][2]<=level) {
			if(pcl[i][1]==1)
				one=max(one,pcl[i][0]);
			else
				primalvalues[pcl[i][1]]+=pcl[i][0];
			if(pcl[i][1]&1)
				odd.pb(pcl[i][1]);
			else
				even.pb(pcl[i][1]);
		}
	}
	sort(all(odd));
	odd.resize(unique(all(odd))-odd.begin());
	sort(all(even));
	even.resize(unique(all(even))-even.begin());
	trace(one);
	primalvalues[1]=one;
	int ans=0,ind=1;
	for(auto &te:primalvalues) {
		ans+=te.se;
		numtoindex[te.fi]=ind;
		ind++;
	}
	PushRelabel G(primalvalues.size()+2);
	for(int i:odd) {
		G.AddEdge(0, numtoindex[i], primalvalues[i]);
	}
	for(int i:odd)
		for(int j:even)
			if(primes[i+j]) {
				trace(i,numtoindex[i],j,numtoindex[j]);
				G.AddEdge(numtoindex[i], numtoindex[j], infi);
			}
	for(int i:even)
		G.AddEdge(numtoindex[i], sz(primalvalues)+1, primalvalues[i]);
	int flow=G.GetMaxFlow(0, sz(primalvalues)+1);
	trace(level,ans,flow);
	return ans-flow;
}
void solve() {
	cin>>n>>k;
	fr(i,1,n)
		fr(j,0,2)
			cin>>pcl[i][j];
	primes[1]=0;
	for(int i=2; i<=200000; i++)
		if(primes[i])
			for(int j=i*i; j<=200000; j+=i)
				primes[j]=0;
	int lo=1,hi=n+1,mid=(lo+hi)/2;
	while(lo<hi) {
		if(check(mid)>=k)
			hi=mid;
		else
			lo=mid+1;
		mid=(lo+hi)/2;
		trace(mid);
	}
	if(mid!=n+1)
		cout<<mid<<endl;
	else
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