//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=2010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
struct twosat{
	int n;
	vector<int> g[N*2];
	bool mark[N*2];
	int s[N],c;
	bool dfs(int x){
		if(mark[x^1])return 0;
		if(mark[x])return 1;
		mark[s[c++]=x]=1;
		for(auto p:g[x])
		if(!dfs(p))
			return 0;
		return 1;
	}
	void init(int _n){
		n=_n;
		for(int i=0;i<n*2;i++){
			g[i].clear();
			mark[i]=0;
		}
	}
	void add(int x,int y,int f){
		g[x*2].push_back(y*2^f);
		g[x*2^1].push_back(y*2^f^1);
		g[y*2].push_back(x*2^f);
		g[y*2^1].push_back(x*2^f^1);
	}
	bool solve(){
		for(int i=0;i<n*2;i+=2)
		if(!mark[i] && !mark[i^1]){
			c=0;
			if(!dfs(i)){
				while(c>0)mark[s[--c]]=0;
				if(!dfs(i^1))return 0;
			}
		}
		return 1;
	}
}ts;
char s[N][N],t[N][N];
void Solve(){
	int n=read(); ts.init(n*2);
	repeat(i,0,n)
		scanf("%s",s[i]);
	repeat(i,0,n)
		scanf("%s",t[i]);
	repeat(i,0,n)
	repeat(j,0,n){
		ts.add(i,j+n,s[i][j]!=t[i][j]);
	}
	puts(ts.solve()?"YES":"NO");
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}