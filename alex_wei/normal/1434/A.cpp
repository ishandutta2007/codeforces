/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//using int = long long

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
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using pdd = pair <double,double>;

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
		for(int i=MAXN-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	} ll bin(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

// Please give me more points.

using namespace IO;
//using namespace math;

const int N=1e5+5;

int n,cnt,ans=1e9,a[N],b[N],buc[N],tot;
struct val{
	int c,id;
	bool operator < (const val &v) const {
		return c<v.c;
	}
}c[N<<3];

void solve(){
	for(int i=1;i<=6;i++)cin>>a[i];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		for(int j=1;j<=6;j++)
			c[++cnt].id=i,c[cnt].c=b[i]-a[j];
	} sort(c+1,c+cnt+1);
	int l=1; buc[c[1].id]++,tot=1;
	for(int i=2;i<=cnt;i++){
		if(!buc[c[i].id])tot++;
		buc[c[i].id]++;
		while(buc[c[l].id]>1)buc[c[l++].id]--;
		if(tot==n)ans=min(ans,c[i].c-c[l].c); 
	} cout<<ans<<endl;
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve(); 
	return 0;
}