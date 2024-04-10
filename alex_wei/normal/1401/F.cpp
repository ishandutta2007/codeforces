/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize(3)
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

const int N=1<<19;

ll bt,q,a[N],val[N<<2],laz[19];

void build(int l,int r,int x,int dep){
	if(l==r){
		val[x]=a[l];
		return;
	} int m=l+r>>1;
	build(l,m,x<<1,dep-1);
	build(m+1,r,x<<1|1,dep-1);
	val[x]=val[x<<1]+val[x<<1|1];
}

void modify(int l,int r,int x,int pos,int v,int dep){
	if(l==r){
		val[x]=v;
		return;
	} int m=l+r>>1;
	if(pos<=m)modify(l,m,(x<<1)^laz[dep],pos,v,dep-1);
	else modify(m+1,r,(x<<1|1)^laz[dep],pos,v,dep-1);
	val[x]=val[x<<1]+val[x<<1|1];
}

ll query(int l,int r,int ql,int qr,int dep,int x){
	if(ql<=l&&r<=qr)return val[x];
	ll m=l+r>>1,ans=0;
	if(ql<=m)ans+=query(l,m,ql,qr,dep-1,(x<<1)^laz[dep]);
	if(m<qr)ans+=query(m+1,r,ql,qr,dep-1,(x<<1|1)^laz[dep]);
	return ans; 
}

int main(){
	cin>>bt>>q; int n=1<<bt;
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1,bt-1);
	for(int i=1;i<=q;i++){
		int op=read(),x=read(),k;
		if(op==1)k=read(),modify(1,n,1,x,k,bt-1);
		if(op==2)for(int i=0;i<x;i++)laz[i]^=1;
		if(op==3)laz[x]^=1;
		if(op==4)k=read(),cout<<query(1,n,x,k,bt-1,1)<<"\n";
	}
	return 0;
}