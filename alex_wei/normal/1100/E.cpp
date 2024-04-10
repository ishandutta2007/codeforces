/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)

//using int = long long
//using i128 = __int128;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(),(x).end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))
#define Time 1.0*clock()/CLOCKS_PER_SEC

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using pdd = pair <double,double>;

pii operator + (pii a,pii b){return {a.fi+b.fi,a.se+b.se};}
pll operator + (pll a,pll b){return {a.fi+b.fi,a.se+b.se};}

namespace IO{
	char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
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
	} inline void print(ll x){if(x>9)print(x/10); pc(x%10+'0');}
}

const int mod=998244353;
const long double Pi=acos(-1);

namespace math{
	const int MAXN=1e6+5;
	ll ksm(ll a,ll b){
		ll s=1,m=a;
		while(b){
			if(b&1)s=s*m%mod;
			m=m*m%mod,b>>=1;
		} return s;
	} ll inv(ll x){return ksm(x,mod-2);}
	ll fc[MAXN],ifc[MAXN];
	void init(){
		fc[0]=1; for(int i=1;i<MAXN;i++)fc[i]=fc[i-1]*i%mod;
		ifc[MAXN-1]=inv(fc[MAXN-1]);
		for(int i=MAXN-2;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	} ll bin(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

// Please give me more points.

using namespace IO;
//using namespace math;

const int N=1e5+5;
int n,m;
struct edge{
	int id,u,v,w;
	bool operator < (const edge &a) const {
		return w>a.w;
	}
}e[N];

vector <int> g[N],ans;
int deg[N],dfn[N],dnum;

bool check(int x){
	queue <int> q;
	mem(deg,0),dnum=0;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=x;i++)g[e[i].u].pb(e[i].v),deg[e[i].v]++;
	for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		int t=q.front(); q.pop();
		dfn[t]=++dnum;
		for(int it:g[t]){
			deg[it]--;
			if(!deg[it])q.push(it);
		}
	} return dnum==n;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w,e[i].id=i;
	sort(e+1,e+m+1);
	int l=0,r=m;
	while(l<r){
		int m=(l+r>>1)+1;
		if(check(m))l=m;
		else r=m-1;
	} check(l);
	for(int i=1;i<=m;i++)if(dfn[e[i].u]>dfn[e[i].v])ans.pb(e[i].id),swap(e[i].u,e[i].v);
	for(int i=1;i<=m;i++)assert(dfn[e[i].u]<dfn[e[i].v]);
	cout<<e[l+1].w<<" "<<ans.size()<<endl;
	for(int it:ans)cout<<it<<" ";
	return 0;
}