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

const int N=2e5+5;
const ll inf=1e18;
ll t,n,a[N],so[N],se[N];
ll cal(int x){return x&1?so[x]-se[x]:se[x]-so[x];}

int main(){
	
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i],so[i]=so[i-1],se[i]=se[i-1];
			if(i&1)so[i]+=a[i];
			else se[i]+=a[i];
		} ll p=2; while(p<=n&&cal(p)>=0)p++;
		if(p>n&&cal(n)==0){puts("YES"); continue;}
		ll sfo=inf,sfe=inf; p=min(p,n-1);
		for(int i=p+2;i<=n;i++)i&1?sfo=min(sfo,cal(i)):sfe=min(sfe,cal(i));
		while(p){
			ll delo=a[p+1]-a[p],dele=a[p]-a[p+1];
			if(p%2==0)swap(delo,dele);
			if(so[n]+delo!=se[n]+dele||sfo+delo-dele<0||sfe+dele-delo<0){
				p&1?sfe=min(sfe,cal(p+1)):sfo=min(sfo,cal(p+1));
				p--; continue;
			} p&1?(sfe=min(sfe,cal(p+1)),so[p]+=delo,so[p+1]+=delo,se[p+1]+=dele):
				(sfo=min(sfo,cal(p+1)),se[p]+=dele,se[p+1]+=dele,so[p+1]+=delo);
			if(cal(p)>=0&&cal(p+1)>=0)break;
			p&1?(so[p]-=delo,so[p+1]-=delo,se[p+1]-=dele):
				(se[p]-=dele,se[p+1]-=dele,so[p+1]-=delo); p--;
		} puts(p?"YES":"NO");
	}
	return 0;
}
/*
1
5
3 1 1 1 2
*/