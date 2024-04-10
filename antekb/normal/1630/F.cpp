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

//github.com/kth-competitive-programming/kactl/blob/master/content/graph/hopcroftKarp.h
//odpowiedz jest w wektorze match, pary dla czesci B
struct matching{
	vector<vi> E;
	vi match, A, B;
	int n, m;
	matching(int n, int m):n(n), m(m){
		E.rsz(n);
		A.rsz(n);
		B.rsz(m);
		match.resize(m, -1);
	}
	void ae(int u, int v){
		E[u].pb(v);
	}
	bool bfs(){
		fill(all(A), 0);
		fill(all(B), 0);
		vi V, V2;
		for(int i:match)if(i!=-1)A[i]=-1;
		for(int i=0; i<n; i++)if(A[i]==0)V.pb(i);
		for(int lev=1; ; lev++){
			bool last=0;
			for(int v:V)for(int u:E[v]){
				if(match[u]==-1) B[u]=lev, last=1;
				else if(match[u]!=v && !B[u])B[u]=lev, V2.pb(match[u]);
			}
			if(last)return 1;
			if(!sz(V2))return 0;
			for(int v:V2)A[v]=lev;
			V=V2;
			V2.clear();
		}
		assert(false);
	}
	bool dfs(int v, int dep){
		if(A[v]!=dep)return 0;
		A[v]=-1;
		for(int u:E[v])if(B[u]==dep+1){
			B[u]=-1;
			if(match[u]==-1 || dfs(match[u], dep+1)){match[u]=v; return 1;}
		}
		return 0;
	}
	int solve(){
		int ans=0;
		while(bfs())for(int i=0; i<n; i++)ans+=dfs(i, 0);
		return ans;
	}
};

const int N=5e4+5, INF=1e9+5, mod=1e9+7;
int czy[N];
int main(){
    BOOST;
    int tt=1;
    cin>>tt;
    while(tt--){
    int n;
    cin>>n;
    vi V(n);
    for(int &i:V)cin>>i;
    for(int i=0; i<n; i++)czy[V[i]]=i+1;
	matching F(n+n+1, n+n+1);
	for(int i:V){
		if(czy[i]){
			//F.ae(czy[i]+n, czy[i], F.inf);
			F.ae(czy[i], czy[i]+n);
			if(V.size()>N/i){
			for(int j=i+i; j<N; j+=i){
				if(czy[j]){
					F.ae(czy[i], czy[j]);
					//F.ae(czy[i], czy[j]+n);
					F.ae(czy[i]+n, czy[j]+n);

				}
			}
			}
			else{
				for(int j:V){
				if(j%i==0 && j>i){
					F.ae(czy[i], czy[j]);
					//F.ae(czy[i], czy[j]+n);
					F.ae(czy[i]+n, czy[j]+n);

				}
			}	
			}
		}
	}
	for(int i:V)czy[i]=0;
	cout<<F.solve()-n<<"\n";
	}
}