#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> pii;
typedef pair<pii, int> piii;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define get(x, y) (((x)>>(y))&1)

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, bit, cnt;
ll h[MAXN];
bool mark[MAXN];
vector<pii> G[MAXN];
vector<ll> gauss;
vector<int> vec;

void add(ll x){
	for (ll a:gauss) if (a&-a&x) x^=a;
	if (!x) return ;
	for (ll &a:gauss) if (x&-x&a) a^=x;
	gauss.pb(x);
}

void dfs(int node, int par){
	cnt++;
	vec.pb(node);
	mark[node]=1;
	for (pii p:G[node]) if (p.first!=par){
		if (mark[p.first]) add(h[node]^h[p.first]^p.second);
		else{
			h[p.first]=h[node]^p.second;
			dfs(p.first, node);
		}
	}
}

int Solve(){
	for (ll a:gauss) if (get(a, bit)){
		ll res=(1ll<<(gauss.size()-1))%mod;
		res*=cnt*(cnt-1)/2%mod;
		return res%mod;
	}
	ll c0=0, c1=0;
	for (int v:vec){
		if (get(h[v], bit)) c1++;
		else c0++;
	}
	ll res=(1ll<<(gauss.size()))%mod;
	res*=c0*c1%mod;
	return res%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v>>x;
		G[u].pb({v, x});
		G[v].pb({u, x});
	}
	for (int i=1; i<=n; i++) if (!mark[i]){
		vec.clear();
		gauss.clear();
		cnt=0;
		dfs(i, i);
		for (bit=0; bit<=60; bit++) ans=(ans+(1ll<<bit)%mod*Solve())%mod;
	}
	cout<<ans<<'\n';
	
	return 0;
}