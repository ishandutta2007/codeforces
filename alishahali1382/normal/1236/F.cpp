#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
const int mod = 1000000007;
const int MAXN = 500010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, ex, ex2;
int H[MAXN], par[MAXN];
ll inv2[MAXN];
ll deg[MAXN];
ll cnt[MAXN];
pii E[MAXN];
vector<int> G[MAXN], C;
vector<pii> C2;
vector<int> vec[MAXN];

void dfs(int node, int p){
	H[node]=H[p]+1;
	par[node]=p;
	for (int v:G[node]) if (v!=p){
		if (!H[v]) dfs(v, node);
		else if (H[v]<H[node]) C.pb(H[node]-H[v]+1), C2.pb({node, par[v]});
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	inv2[0]=1;
	for (int i=1; i<MAXN; i++) inv2[i]=inv2[i-1]*(mod+1)/2%mod;
	
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
		E[i]={u, v};
		deg[u]++;
		deg[v]++;
	}
	dfs(1, 0);
	ex=n*inv2[1]-m*inv2[2];
	for (int c:C) ex+=inv2[c];
	ex%=mod;
	
	ex2=(n*(n-1)%mod)*inv2[2]%mod;
	ex2+=n*inv2[1]%mod;
	
	//debug(ex2*8%mod)
	
	for (int i=0; i<m; i++){
		int u=E[i].first, v=E[i].second;
		ll d=deg[u]+deg[v]-2;
		ex2+=inv2[2];
		ex2+=d*inv2[3]%mod;
		ex2+=(m-d-1)*inv2[4]%mod;
	}
	ex2%=mod;
	
	
	for (pii p:C2){
		for (int v=p.first; v!=p.second; v=par[v]) vec[v].pb(H[p.first]-H[p.second]); 
	}
	
	
	
	ll sum=0;
	for (int c:C) sum+=inv2[c];
	sum%=mod;
	for (pii p:C2){
		ll tmp=sum;
		for (int v=p.first; v!=p.second; v=par[v]) for (int c:vec[v]) tmp+=inv2[c-1]-inv2[c];
		int c=H[p.first]-H[p.second];
		tmp-=c*(inv2[c-1]-inv2[c]);
		tmp-=inv2[c];
		tmp++;
		tmp%=mod;
		tmp=tmp*inv2[c]%mod;
		ex2+=tmp;
	}
	ex2%=mod;
	
	
	
	for (int c:C){
		ex2+=2*inv2[c]*(c+((n-c)*inv2[1]%mod))%mod;
	}
	ex2%=mod;
	
	
	for (int i=1; i<=n; i++){
		ex2-=(inv2[1]*deg[i] + inv2[2]*(m-deg[i]))%mod;
	}
	ex2%=mod;
	
	
	//ll shit=ex2;
	
	
	for (pii p:C2){
		sum=0;
		for (int v=p.first; v!=p.second; v=par[v]) sum+=deg[v];
		int c=H[p.first]-H[p.second];
		sum-=2*c;
		ll tmp=(c + sum*inv2[1] + (m-c-sum)*inv2[2])%mod;
		ex2-=2*tmp*inv2[c]%mod; 
	}
	ex2%=mod;
	
	
	//debug((ex2-shit)*8%mod)
	
	
	
	ans=ex2-ex*ex;
	ans%=mod;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	/*
	debug((ex+mod)*8%mod)
	debug((ex2+mod)*8%mod)
	*/
	return 0;
}