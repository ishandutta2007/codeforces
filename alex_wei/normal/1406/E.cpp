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

const int N=1e5+5;

int n,ori,cnt,p[N],pr[N],pre[N];

int pd[N],res,gt;
void del(int x){for(int j=x;j<=ori;j+=x)if(!pd[j])res--,pd[j]=1;}

void pa(int x){cout<<"A "<<x<<endl,cin>>gt;}
void pb(int x){cout<<"B "<<x<<endl,cin>>gt;}

int find(int st){
	if(st==0)return 1; int lim=st/2;
	for(int i=st;i>lim;i--)pb(pr[i]),del(pr[i]); pa(1);
	if(gt!=res){
		int ans=1;
		for(int i=st;i>lim;i--){
			ll tmp=pr[i];
			while(tmp<=n){
				pa(tmp); if(!gt)break;
				tmp*=pr[i];
			} tmp/=pr[i],n/=tmp;
			if(tmp>1)ans*=tmp;
		} return ans*find(min(lim,pre[n]));
	} else return find(lim);
}

void solve(){
	cin>>n,ori=res=n;
	for(int i=2;i<=n;i++){
		if(!p[i]){
			pr[++cnt]=i;
			for(int j=i+i;j<=n;j+=i)p[j]=1;
		} pre[i]=pre[i-1]+(!p[i]);
	} cout<<"C "<<find(cnt)<<endl;
}

int main(){
	int t=1;
	while(t--)solve(); 
	return 0;
}