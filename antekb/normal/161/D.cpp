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

//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=2e5+5, K=505, INF=1e9+5, mod=1e9+7;
//github.com/bqi343/USACO/blob/master/Implementations/kactl.pdf
int k;
ll ans=0;
int dep[N][K];
template <int SZ> struct cent{
	int siz[SZ], par[SZ], uzy[SZ];
	vi E[SZ];
	int prv[SZ];//bezposrednio poprzedza
	vi dist[SZ];//odleglosci od wszystkich poprzedzajacych centroidow, w kolejnosci od gory
	void ae(int u ,int v){E[u].pb(v); E[v].pb(u);}
	void dfs(int v){
		//cout<<v<<" "<<par[v]<<"\n";
		siz[v]=1;
		for(int u:E[v]){
			if(!uzy[u] && u!=par[v]){
				par[u]=v;
				dfs(u);
				siz[v]+=siz[u];
			}
		}
	}
	void finddist(int v, int d, int anc, int sub){
		if(d<K){dep[0][d]++;dep[sub][d]++;}
		for(int u:E[v])if(!uzy[u] && u!=anc)finddist(u, d+1, v, sub);
	}
	int findcen(int v){
		par[v]=-1;
		dfs(v);
		int roz=siz[v];
		for(;;){
			//cout<<v<<" "<<par[v]<<"\n";
			int opt=0;
			for(int u:E[v]){
				if(!uzy[u] && u!=par[v] && siz[u]>siz[opt])opt=u;
			}
			if(siz[opt]*2>roz)v=opt;
			else return v;
		}
	}
	void gen(int root, int przed){
		//cout<<root<<" "<<przed<<"a\n";
		root=findcen(root);
		//cout<<root<<"\n";
		prv[root]=przed;
		uzy[root]=1;
		for(int u:E[root])if(!uzy[u])finddist(u, 1, root, u);
		vi V;
		for(int u:E[root])if(!uzy[u])V.pb(u);
		//cout<<root<<" "<<ans<<"\n";
		dep[0][0]=1;
		for(int i=0; i<K && dep[0][i]; i++){
			//cout<<i<<"a"<<ans<<"\n";
			if(2*i==k)ans+=dep[0][k/2]*1ll*(dep[0][k/2]-1)/2;
			else if(i<=k)ans+=dep[0][i]*1ll*dep[0][k-i];
			dep[0][i]=0;
			if(i){
				vi V2;
				for(int j:V){
					if(2*i==k)ans-=dep[j][k/2]*1ll*(dep[j][k/2]-1)/2;
					else if(i<=k)ans-=dep[j][i]*1ll*dep[j][k-i];
					if(dep[j][i])V2.pb(j);
					dep[j][i]=0;
				}
				V=V2;
			}
		}
		//cout<<root<<" "<<ans<<"\n";
		for(int u:E[root])if(!uzy[u])gen(u, root);
	}
	void init(){siz[0]=-1, gen(1, -1);} 
};
int main(){
	BOOST;
	int n;
	cin>>n>>k;
	cent<N> g;
	for(int i=1; i<n; ++i){
		int u, v;
		cin>>u>>v;
		g.ae(u, v);
	}
	g.init();
	cout<<ans;
}