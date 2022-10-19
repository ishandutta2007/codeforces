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

const int N=2e5+5, INF=1e9+5, mod=1e9+7;
bool vis[N];
vector<int> E[N];
int cnt=0;
bool c;
int dfs(int v){
	vis[v]=1;
	int res=1;
	for(int u:E[v]){
		if(!vis[u]){
			if(dfs(u))res=0;
		}
	}
	if(v!=1 && !(res&1))cnt++;
	else{
		for(int u:E[v])if(u==1)c=1;
	}
	return res;
}
int main(){
	//BOOST;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1; i<n; i++){
			int a, b;
			cin>>a>>b;
			E[a].pb(b);
			E[b].pb(a);
		}
		dfs(1);
		cout<<n-1-2*cnt+1-c<<"\n";
		for(int i=1; i<=n; i++)vis[i]=0, E[i].clear();
		cnt=0;
		c=0;
	}
}