#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const ll mod = 1000000007, hashmod=10007;
const ll MAXN = 200010, H1=12345, H2=29;

int n, m, k, u, v, x, y, t, a, b, out=1;
int ans[MAXN];
vector<int> G[MAXN];
map<int, ll> hashvalue[MAXN];
map<int, int> mp;

void dfshashdown(int node, int par){
	for (int i:G[node]) if (i!=par) dfshashdown(i, node);
	if (node==1) return ;
	vector<ll> vec;
	for (int i:G[node]) if (i!=par) vec.pb(hashvalue[node][i]);
	
	ll val=H1, sum=0;
	for (ll i:vec) val=(val*i)%mod, sum+=i;
	sum%=mod;
	val^=sum;
	mp[val]++;
	hashvalue[par][node]=val;
}

ll inv(ll x){
	ll res=1;
	for (ll tav=mod-2, tmp=x; tav; tav>>=1, tmp=tmp*tmp%mod) if (tav&1) res=res*tmp%mod;
	return res;
}

void dfshashup(int node, int par){
	vector<ll> vec;
	for (int i:G[node]) if (i!=par) vec.pb(hashvalue[node][i]);
	if (node!=1) vec.pb(hashvalue[node][par]);
	
	ll val=H1, sum=0;
	for (ll i:vec) val=val*i%mod, sum+=i;
	for (int i:G[node]) if (i!=par){
		ll tmp=hashvalue[node][i];
		tmp=(val*inv(tmp)%mod)^((sum-tmp)%mod);
		hashvalue[i][node]=tmp;
	}
	
	for (int v:G[node]) if (v!=par) dfshashup(v, node);
}

void change(int a, int b){
	if (!(--mp[hashvalue[a][b]])) mp.erase(hashvalue[a][b]);
	mp[hashvalue[b][a]]++;
}

void dfs(int node, int par){
	ans[node]=mp.size();
	for (int i:G[node]) if (i!=par){
		change(node, i);
		dfs(i, node);
		change(i, node);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n-1; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfshashdown(1, 1);	
	dfshashup(1, 1);
	
	dfs(1, 1);
	for (int i=1; i<=n; i++) if (ans[i]>ans[out]) out=i;
	cout<<out<<'\n';

	return 0;
}