/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize(3)

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

int n,q,l[N],r[N],val[N<<2],laz[N<<2];
string s,t;
void build(int l,int r,int x){
	laz[x]=0;
	if(l==r){
		val[x]=t[l-1]-'0';
		return;
	} int m=l+r>>1;
	build(l,m,x<<1),build(m+1,r,x<<1|1);
	val[x]=val[x<<1]+val[x<<1|1];
}
void push(int l,int r,int x){
	if(laz[x]){
		int m=l+r>>1;
		if(laz[x]==1){
			laz[x<<1]=laz[x<<1|1]=1;
			val[x<<1]=val[x<<1|1]=0;
		} else{
			laz[x<<1]=laz[x<<1|1]=2;
			val[x<<1]=m-l+1,val[x<<1|1]=r-m;
		} laz[x]=0;
	}
}
void modify(int l,int r,int ql,int qr,int x,int v){
	if(ql<=l&&r<=qr){
		if(v==1)laz[x]=1,val[x]=0;
		else laz[x]=2,val[x]=r-l+1;
		return;
	} int m=l+r>>1; push(l,r,x);
	if(ql<=m)modify(l,m,ql,qr,x<<1,v);
	if(m<qr)modify(m+1,r,ql,qr,x<<1|1,v);
	val[x]=val[x<<1]+val[x<<1|1];
}
int query(int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr)return val[x];
	int m=l+r>>1,ans=0; push(l,r,x);
	if(ql<=m)ans+=query(l,m,ql,qr,x<<1);
	if(m<qr)ans+=query(m+1,r,ql,qr,x<<1|1);
	return ans;
}
#define gg {puts("NO"); return;}
void solve(){
	cin>>n>>q>>s>>t;
	build(1,n,1);
	for(int i=1;i<=q;i++)cin>>l[i]>>r[i];
	for(int i=q;i;i--){
		int c=query(1,n,l[i],r[i],1);
		int len=r[i]-l[i]+1;
		if(len%2==0&&c==len/2)gg;
		if(c<=len/2)modify(1,n,l[i],r[i],1,1);
		else modify(1,n,l[i],r[i],1,2);
	} for(int i=1;i<=n;i++)if(s[i-1]-'0'!=query(1,n,i,i,1))gg;
	puts("YES");
}

int main(){
//	ios::sync_with_stdio(false),cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)solve(); 
	return 0;
}