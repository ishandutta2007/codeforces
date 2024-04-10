/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

// Templates start.

namespace IO{
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math{
	const int mod=998244353;
	const int maxn=1e6+5;

	ll ksm(ll a,ll b){ll s=1,m=a; while(b){if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
	ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n){
		fc[0]=1; for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]); for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=5e5+5;

ll n,p[N],a[N],b[N];
vector <int> tmp;
bool cmpa(int x,int y){return a[x]!=a[y]?a[x]<a[y]:x<y;}
bool cmpb(int x,int y){return b[x]!=b[y]?b[x]<b[y]:x<y;}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],p[i]=i,b[i]=a[i]; sort(p,p+n,cmpa);
	int cnt=0;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(a[i]>a[j])cnt++; cout<<cnt<<endl;
//	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
//		if(a[i]>a[j])cout<<i<<" "<<j<<endl;
	for(int i=0;i<n;i++,tmp.clear()){
		for(int j=p[i]+1;j<n;j++)if(a[j]<a[p[i]])tmp.pb(j);
		sort(all(tmp),cmpb);
		for(int j=tmp.size()-1;j>=0;j--)swap(b[p[i]],b[tmp[j]]),cout<<p[i]+1<<" "<<tmp[j]+1<<endl;
	}
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve(); 
	return 0;
}