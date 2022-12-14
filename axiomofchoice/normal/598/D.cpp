#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=1010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
struct DSU{
	int a[N*N],sz[N*N];
	void init(int n){
		iota(a,a+n+1,0);
		fill(sz,sz+n+1,0);
	}
	int fa(int x){
		return a[x]==x?x:a[x]=fa(a[x]);
	}
	void add(int x){
		x=fa(x); sz[x]++;
	}
	bool query(int x,int y){
		return fa(x)==fa(y);
	}
	void join(int x,int y){
		x=fa(x),y=fa(y);
		if(x==y)return;
		a[x]=y; sz[y]+=sz[x];
	}
	int operator[](int x){return fa(x);}
}d;
int n,m;
int f(int x,int y){
	return x*m+y;
}
char s[N][N];
void Solve(){
	n=read(),m=read(); int q=read(); d.init(n*m);
	repeat(i,0,n)scanf("%s",s[i]);
	repeat(i,0,m)s[n][i]=0;
	repeat(i,0,n)
	repeat(j,0,m){
		if(s[i][j]=='.' && s[i+1][j]=='.')
			d.join(f(i,j),f(i+1,j));
		if(s[i][j]=='.' && s[i][j+1]=='.')
			d.join(f(i,j),f(i,j+1));
		if(s[i][j]=='*')
			d.add(f(i+1,j)),d.add(f(i,j+1));
		if(s[i+1][j]=='*')d.add(f(i,j));
		if(s[i][j+1]=='*')d.add(f(i,j));
	}
	//orz(f(1,2));
	while(q--){
		int x=read()-1,y=read()-1;
		printf("%lld\n",d.sz[d[f(x,y)]]);
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}