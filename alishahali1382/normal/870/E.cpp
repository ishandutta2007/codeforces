#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans=1;
int X[MAXN], Y[MAXN];
bool mark[MAXN];
ll tav[MAXN];
vector<int> G[MAXN], compx, compy;

pii dfs(int node, int par){
	pii res={1, 0};
	mark[node]=1;
	for (int v:G[node]) if (v!=par){
		if (mark[v]) res.second=1;
		else{
			pii tmp=dfs(v, node);
			res.first+=tmp.first;
			res.second+=tmp.second;
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*2%mod;
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>X[i]>>Y[i];
		compx.pb(X[i]);
		compy.pb(Y[i]);
	}
	sort(all(compx));
	sort(all(compy));
	for (int i=1; i<=n; i++){
		X[i]=lower_bound(all(compx), X[i])-compx.begin();
		Y[i]=lower_bound(all(compy), Y[i])-compy.begin();
		G[X[i]].pb(n+Y[i]);
		G[Y[i]+n].pb(X[i]);
	}
	for (int i=1; i<MAXN; i++) if (!mark[i]){
		pii p=dfs(i, -1);
		if (p.second) ans=ans*tav[p.first]%mod;
		else ans=ans*(tav[p.first]-1)%mod;
	}
	cout<<ans<<"\n";
	
	return 0;
}