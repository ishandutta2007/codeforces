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
vi E[N];
int col[N], par[N], siz[N];
int num[N];
ll sum[N], ans[N];
multiset<int> S;
void prep(int v){
	siz[v]=1;
	for(int u:E[v]){
		if(u!=par[v]){
			par[u]=v;
			prep(u);
			siz[v]+=siz[u];
		}
	}
}
void fill(int v, int c){
	S.erase(S.find(num[col[v]]));
	sum[num[col[v]]]-=col[v];
	num[col[v]]+=c;
	sum[num[col[v]]]+=col[v];
	S.insert(num[col[v]]);
	for(int u:E[v])if(u!=par[v])fill(u, c);
}
void solve(int v){
	int big=0;
	for(int u:E[v])if(u!=par[v] && siz[u]>siz[big])big=u;
	for(int u:E[v])if(u!=par[v] && u!=big)solve(u), fill(u, -1);
	if(big)solve(big);
	for(int u:E[v])if(u!=par[v] && u!=big)fill(u, 1);
	S.erase(S.find(num[col[v]]));
	sum[num[col[v]]]-=col[v];
	num[col[v]]++;
	sum[num[col[v]]]+=col[v];
	S.insert(num[col[v]]);
	ans[v]=sum[*S.crbegin()];
}
int main(){
	BOOST;
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)cin>>col[i], S.insert(0);
	for(int i=1; i<n; i++){
		int u, v;
		cin>>u>>v;
		E[u].pb(v);
		E[v].pb(u);
	}
	prep(1);
	solve(1);
	for(int i=1; i<=n; i++)cout<<ans[i]<<" ";
}