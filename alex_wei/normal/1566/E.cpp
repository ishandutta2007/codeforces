/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)

//using int = long long
//using i128 = __int128;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using pdd = pair <double,double>;
using vint = vector <int>;
using vpii = vector <pii>;

#define fi first
#define se second
#define pb emplace_back
#define mpi make_pair
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))
#define mcpy(x,y) memcpy(x,y,sizeof(y))
#define Time 1.0*clock()/CLOCKS_PER_SEC

pii operator + (pii a,pii b){return {a.fi+b.fi,a.se+b.se};}
pll operator + (pll a,pll b){return {a.fi+b.fi,a.se+b.se};}

namespace IO{
	char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<24],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)
	inline ll read(){
		ll x=0; bool sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	inline void print(ll x){
		if(x<0)pc('-'),print(-x);
		else{
			if(x>9)print(x/10);
			pc(x%10+'0');
		}
	}
}

const int mod=998244353;
const long double Pi=acos(-1);

namespace math{
	const int MAXN=2e6+5;

	ll ksm(ll a,ll b,ll p){
		ll s=1,m=a;
		while(b){
			if(b&1)s=s*m%p;
			m=m*m%p,b>>=1;
		} return s;
	}
	ll ksm(ll a,ll b){
		ll s=1,m=a;
		while(b){
			if(b&1)s=s*m%mod;
			m=m*m%mod,b>>=1;
		} return s;
	}
	ll inv(ll x){return ksm(x,mod-2);}

	ll fc[MAXN],ifc[MAXN];
	void init(int n){
		assert(n<MAXN);
		fc[0]=1;
		for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll bin(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

using namespace IO;
//using namespace math;

const int N=2e5+5;
vector <int> e[N];
int n,have,leaf,bud,g[N];
void dfs(int id,int f){
	int tot=0; g[id]=0;
	for(int it:e[id])
		if(it!=f){
			dfs(it,id);
			if(!g[it])tot++;
		}
	if(id==1)return;
	if(tot==0)leaf++,have|=f==1;
	else bud++,g[id]=1;
	
}
void solve(){
	int ans=0; cin>>n,leaf=bud=have=0;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		e[u].pb(v),e[v].pb(u);
	} dfs(1,0);
	cout<<leaf-bud+(!have)<<endl;
}

int main(){
	int T; cin>>T;
	while(T--)solve();
	return 0;
}