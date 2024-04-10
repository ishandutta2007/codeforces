/*
	Powered by C++11.
	Author : Alex_Wei.
*/

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
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void print(int x){
		if(x<0)return pc('-'),print(-x),void();
		if(x>9)print(x/10);
		pc(x%10+'0');
	}
}

namespace math{
	const int mod=99824353;
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

const int N=3e5+5;

int n,m,node,rt[N],val[N<<5],ls[N<<5],rs[N<<5];
void upd(int x){
	val[x]=val[ls[x]]+val[rs[x]];
}
void ins(int l,int r,int p,int &x,int pre){
	val[x=++node]=val[pre];
	if(l==r)return val[x]++,void();
	int m=l+r>>1;
	if(p<=m)ins(l,m,p,ls[x],ls[pre]),rs[x]=rs[pre];
	else ins(m+1,r,p,rs[x],rs[pre]),ls[x]=ls[pre];
	upd(x);
}
int query(int l,int r,int k,int x,int y){
	if(l==r)return l;
	int m=l+r>>1,sz=val[ls[y]]-val[ls[x]];
	if(sz<k)return query(m+1,r,k-sz,rs[x],rs[y]);
	return query(l,m,k,ls[x],ls[y]);
}
int check(int l,int r,int p,int x,int y){
	if(l==r)return val[y]-val[x];
	int m=l+r>>1;
	if(p<=m)return check(l,m,p,ls[x],ls[y]);
	return check(m+1,r,p,rs[x],rs[y]);
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)ins(1,n,read(),rt[i],rt[i-1]);
	for(int i=1;i<=m;i++){
		int l=read(),r=read(),k=read();
		int rk=1,ans=-1,nd=(r-l+1)/k+1;
		while(rk<=r-l+1){
			int q=query(1,n,rk,rt[l-1],rt[r]);
			if(check(1,n,q,rt[l-1],rt[r])>=nd){
				ans=q;
				break;
			} rk+=nd;
		} printf("%d\n",ans);
	}
	return 0;
}