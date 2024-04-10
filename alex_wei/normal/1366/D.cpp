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
	ll C(ll n,ll m){
		if(n<m)return 0;
		return fc[n]*ifc[m]%mod*ifc[n-m]%mod;
	}
}

// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=5e5+5;
const int M=1e7+5;

int n,a[N],tg[M],tg2[M],pr[M],pd[N];

int main(){
	n=read();
	for(int i=2;i*i<M;i++)
		if(!pr[i])
			for(int j=i*i;j<M;j+=i){
				pr[j]=1;
				if(!tg[j])tg[j]=i;
			}
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(!tg[a[i]])cout<<"-1 ";
		else{
			int tmp=a[i],div=tg[a[i]];
			while(tmp%div==0)tmp/=div;
			if(tmp==1)cout<<"-1 ";
			else cout<<tmp<<" ",a[i]/=tmp,pd[i]=1;
		}
	} puts("");
	for(int i=1;i<=n;i++){
		if(pd[i])cout<<a[i]<<" ";
		else cout<<"-1 ";
	}
	return 0;
}