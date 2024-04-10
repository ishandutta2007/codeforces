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

vector <ll> x,y;
ll n,a[N]; 

void solve(){
	cin>>n;
	x.clear(),y.clear();
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0)x.pb(a[i]);
		else y.pb(a[i]);
	} ll ans=-1e18;
	sort(x.begin(),x.end()),sort(y.begin(),y.end());
	if(n==5){
		cout<<a[1]*a[2]*a[3]*a[4]*a[5]<<endl;
		return;
	}
	rev(y);
	if(y.size()>=5)ans=max(ans,y[0]*y[1]*y[2]*y[3]*y[4]);
	if(y.size()>=3&&x.size()>=2)
		ans=max(ans,y[0]*y[1]*y[2]*x[0]*x[1]);
	if(y.size()>=1&&x.size()>=4)
		ans=max(ans,y[0]*x[0]*x[1]*x[2]*x[3]);
	rev(x);
	if(y.size()==0)
		ans=max(ans,x[0]*x[1]*x[2]*x[3]*x[4]);
	cout<<ans<<endl;
}

int main(){
	int t=1;
	cin>>t;
	while(t--)solve(); 
	return 0;
}