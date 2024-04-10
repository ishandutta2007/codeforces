/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair <int,int>
#define pll pair <ll,ll>
#define pdd pair <double,double>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

// Templates start.

namespace IO{
	char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	inline void print(int x){if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math{
	const int mod=1e9+7;
	const int maxn=1e6+5;

	ll ksm(ll a,ll b){ll s=1,m=a; while(b){if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
	ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n){
		fc[0]=1;
		for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=3e5+5;

vector <int> e[N];
int vis[N],dis[N];
void dfs(int id,int f,int v){
	dis[id]=v;
	for(int it:e[id])if(it!=f)dfs(it,id,v+1);
}
void dfs(int id,int f,int v,int lim){
	vis[id]=1; if(v==lim)return;
	for(int it:e[id])if(it!=f)dfs(it,id,v+1,lim);
}

void solve(){
	int n,a,b,da,db;
	cin>>n>>a>>b>>da>>db;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int x,y; cin>>x>>y;
		e[x].pb(y),e[y].pb(x);
	}
	dfs(1,0,0);
	int pos=1; for(int i=2;i<=n;i++)if(dis[i]>dis[pos])pos=i;
	dfs(pos,0,0);
	int len=0; for(int i=1;i<=n;i++)len=max(len,dis[i]);
	if(da*2>=len)puts("Alice");
	else if(da*2>=db)puts("Alice");
	else{
		for(int i=1;i<=n;i++)vis[i]=0;
		dfs(a,0,0,da);
		if(vis[b])puts("Alice");
		else puts("Bob");
	}
}


int main(){
	int t=1;
	cin>>t;
	while(t--)solve();
	return 0;
}