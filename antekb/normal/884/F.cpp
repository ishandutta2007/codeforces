#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

//https://cp-algorithms.com/graph/dinic.html
//numeracja od 0
struct flow{
	using T=ll;
	const T inf=numeric_limits<T>::max();
	struct Edge{
		int v, u;
		T cap, flo=0, cost;
		Edge(int v, int u, T cap, T cost) : v(v), u(u), cap(cap), cost(cost){}
	};
	int n, s, t;
	vector<vi> adj;
	vi par;
	vector<T> dist;
	vector<Edge> edg;
	flow(int n, int s, int t):n(n), s(s), t(t){
		adj.rsz(n);
		par.rsz(n);
		dist.rsz(n);
	}
	void ae(int u, int v, T cap, T cost){
		adj[u].pb(sz(edg));
		edg.pb(Edge(u, v, cap, cost));
		adj[v].pb(sz(edg));
		edg.pb(Edge(v, u, 0, -cost));
	}
	//powinno byc szybsze niz O(nm)
	//zapetla sie gdy istnieje ujemny cykl
	//jak nie dziala przerobic na Bellmana-Forda
	bool bfs(){
		fill(all(dist), inf);
		queue<int> Q;
		vi inq(n);
		Q.push(s);
		dist[s]=0;
		inq[s]=1;
		while(sz(Q)){
			int v=Q.front();
			inq[v]=0;
			Q.pop();
			for(int e:adj[v]){
				if(edg[e].flo!=edg[e].cap && dist[edg[e].u]>dist[v]+edg[e].cost){
					dist[edg[e].u]=dist[v]+edg[e].cost;
					par[edg[e].u]=e;
					if(!inq[edg[e].u])inq[edg[e].u]=1, Q.push(edg[e].u);
				}
			}
		}
		return dist[t]!=inf;
	}
	//odpalac z K=-1
	pair<T, T> solve(T K){
		if(K=-1)K=inf;
		T ans=0, cost=0;
		while(K-ans && bfs()){
			int v=t;
			T C=K-ans;
			while(v!=s){
				C=min(C, edg[par[v]].cap-edg[par[v]].flo);
				v=edg[par[v]].v;
			}
			v=t;
			cost+=C*dist[t];
			ans+=C;
			while(v!=s){
				edg[par[v]].flo+=C;
				edg[par[v]^1].flo-=C;
				v=edg[par[v]].v;
			}
		}
		return mp(ans, cost);
	}
};

const int N=2e5+5, INF=1e9+5, mod=1e9+7, A=26;
int tab[A];
int main(){
	BOOST;
    int n;
    cin>>n;
    str s;
    cin>>s;
    for(char c:s)tab[c-'a']++;

    flow F(2+n/2+A, n/2+A, n/2+A+1);
	vector<int> b;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		b.pb(x);
	}
	for(int i=0; i<n/2; i++){
		F.ae(F.n-2, i, 2, 0);
		for(int j=0; j<A; j++){
			int c=0;
			if(s[i]==j+'a')c=b[i];
			if(s[n-i-1]==j+'a')c=max(c, b[n-1-i]);
			F.ae(i, n/2+j, 1, -c);
		}
	}

	for(int i=0; i<A; i++)F.ae(n/2+i, F.n-1, tab[i], 0);

	auto a=F.solve(-1);
	cout<<-a.nd;
}