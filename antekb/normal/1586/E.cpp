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

const int N=3e5+5, mod=1e9+7, INF=1e9+5;
vi E[N];
int par[N], dep[N];
void dfs(int v){
	for(int u:E[v]){
		if(!dep[u]){
			par[u]=v;
			dep[u]=dep[v]+1;
			dfs(u);
		}
	}
}
int main(){
	BOOST;
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		E[u].pb(v);
		E[v].pb(u);
	}
	dep[1]=1;
	dfs(1);
	int q;
	cin>>q;
	vector<int> V(n+1);
	vector<vector<int>> ans;
	for(int i=0; i<q; i++){
		int a, b;
		cin>>a>>b;
		V[a]^=1;
		V[b]^=1;
		vi A, B;
		A.pb(a);
		B.pb(b);
		while(a!=b){
			if(dep[a]>dep[b]){
				A.pb(par[a]);
				a=par[a];
			}
			else{
				B.pb(par[b]);
				b=par[b];
			}
		}
		if(A.back()==B.back())B.pp();
		while(B.size()){
			A.pb(B.back());
			B.pp();
		}
		ans.pb(A);
	}
	int ile=0;
	for(int i=1; i<=n; i++)ile+=V[i];
	if(ile)cout<<"NO\n"<<ile/2;
	else{
		cout<<"YES\n";
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i].size()<<"\n";
			for(int j:ans[i])cout<<j<<" ";
			cout<<"\n";
		}
	}
}