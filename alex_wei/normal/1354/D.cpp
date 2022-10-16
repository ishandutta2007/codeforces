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

//namespace IO{
//	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
//	#ifdef __WIN64
//		#define gc getchar()
//	#else
//		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
//	#endif
//	#define pc(x) (*O++=x)
//	#define flush() fwrite(obuf,O-obuf,1,stdout)
//
//	inline int read(){
//		int x=0,sign=0; char s=getchar();
//		while(!isdigit(s))sign|=s=='-',s=getchar();
//		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
//		return sign?-x:x;
//	}
//	void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}
//}

//namespace math{
//	const int mod=998244353;
//	const int maxn=1e6+5;
//
//	ll ksm(ll a,ll b){ll s=1,m=a; while(b){if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
//	ll inv(ll x){return ksm(x,mod-2);}
//
//	ll fc[maxn],ifc[maxn];
//	void init_m(int n){
//		fc[0]=1; for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
//		ifc[n]=inv(fc[n]); for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
//	}
//	ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
//}

// Templates end. Please give me more points.

//using namespace IO;
//using namespace math;

const int N=1e6+1;

int n,q,a,x,val[N<<2];

void modify(int l,int r,int p,int x,int v){
	val[x]+=v;
	if(l==r)return;
	int m=l+r>>1;
	if(p<=m)modify(l,m,p,x<<1,v);
	else modify(m+1,r,p,x<<1|1,v);
}
int query(int l,int r,int x,int k){
	if(l==r)return l;
	int sz=val[x<<1],m=l+r>>1;
	if(k<=sz)return query(l,m,x<<1,k);
	else return query(m+1,r,x<<1|1,k-sz);
}

int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)scanf("%d",&a),modify(1,n,a,1,1);
	for(int i=1;i<=q;i++){
		scanf("%d",&x);
		if(x<0)x=query(1,n,1,-x),modify(1,n,x,1,-1);
		else modify(1,n,x,1,1);
	}
	if(!val[1])cout<<0<<endl;
	else cout<<query(1,n,1,1);
	return 0;
}