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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010;

int n, m, k, u, v, x, y, t, a, b, ans;
int deg[MAXN], P[MAXN];
int par[MAXN], mark[MAXN];

int ask(int v){
	cout<<"? "<<v<<endl;
	int x;
	cin>>x;
	return x;
}

int getpar(int x){ return (par[x]==x?x:par[x]=getpar(par[x]));}
void join(int x, int y){ par[getpar(x)]=getpar(y);}

int Main(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>deg[i];
	iota(par+1, par+n+1, 1);
	fill(mark+1, mark+n+1, 0);
	iota(P+1, P+n+1, 1);
	sort(P+1, P+n+1, [](int i, int j){
		return deg[i]>deg[j];
	});
	
	for (int i=1; i<=n; i++){
		int v=P[i];
		if (mark[v]) continue ;
		mark[v]=1;
		while (deg[v]--){
			int u=ask(v);
			join(u, v);
			if (mark[u]) break ;
			mark[u]=1;
		}
	}
	cout<<"! ";
	for (int i=1; i<=n; i++) cout<<getpar(i)<<" ";
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}