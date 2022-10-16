#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

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

namespace IO{
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,1,O-obuf,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void rec_print(int x){if(x>=10)rec_print(x/10);pc(x%10+'0');}
	void print(int x){if(x<0)pc('-'),x=-x;rec_print(x);}
}

namespace math{
	const int mod=998244353;
	const int maxn=2e6+5;

	ll ksm(ll a,ll b,ll p){
		ll s=1,m=a%p;
		while(b){
			if(b&1)s=s*m%p;
			m=m*m%p,b>>=1;
		} return s;
	} ll ksm(ll a,ll b){
		ll s=1,m=a%mod;
		while(b){
			if(b&1)s=s*m%mod;
			m=m*m%mod,b>>=1;
		} return s;
	} ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n){
		fc[0]=1;
		for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	} ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

using namespace IO;
//using namespace math;

template <class T1,class T2> void cmin(T1 &a,T2 b){a=a<b?a:b;}
template <class T1,class T2> void cmax(T1 &a,T2 b){a=a>b?a:b;}

const int N=1e6+5;
const int inf=0x3f3f3f3f;

int n,e,a[N],f[N];
void solve(){
	cin>>n>>e;
	ll ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=e;i++){
		for(int j=i;j<=n;j+=e){
			if(!f[a[j]]){
				ll l=1,r=1;
				for(int k=j-e;k>=1;k-=e)
					if(a[k]!=1)break;
					else l++;
				for(int k=j+e;k<=n;k+=e)
					if(a[k]!=1)break;
					else r++;
				ans+=l*r-1;
			}
		}
	}
	cout<<ans<<"\n";
}

int main(){
	f[1]=1;
	for(int i=2;i<N;i++)
		if(!f[i])
			for(int j=i+i;j<N;j+=i)
				f[j]=1;
	int t=1;
	cin>>t;
	while(t--)solve();

	return 0;
}