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
const int inf=0x3f3f3f3f;

ll n,h[N],b[N],f[N];
ll val[N<<2],laz[N<<2];
ll top,stc[N],len[N];
void push(int x){
	if(laz[x]!=0){
		val[x<<1]+=laz[x];
		val[x<<1|1]+=laz[x];
		laz[x<<1]+=laz[x];
		laz[x<<1|1]+=laz[x];
		laz[x]=0; 
	}
}
void modify(int l,int r,int ql,int qr,int x,ll v){
	if(ql<=l&&r<=qr){
		val[x]+=v,laz[x]+=v;
		return;
	}
	int m=l+r>>1; push(x);
	if(ql<=m)modify(l,m,ql,qr,x<<1,v);
	if(m<qr)modify(m+1,r,ql,qr,x<<1|1,v);
	val[x]=max(val[x<<1],val[x<<1|1]);
}
ll query(int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr)return val[x];
	ll m=l+r>>1,ans=-1e18; push(x);
	if(ql<=m)ans=max(ans,query(l,m,ql,qr,x<<1));
	if(m<qr)ans=max(ans,query(m+1,r,ql,qr,x<<1|1));
	return ans; 
}

void solve(){
	cin>>n,mem(f,0x9f),mem(val,0x9f),f[0]=0,top++;
	modify(0,n,0,0,1,-val[0]);
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		modify(0,n,i-1,i-1,1,b[i]);
		int l=1;
		while(h[i]<h[stc[top]]){
			modify(0,n,i-l-len[top],i-l-1,1,b[i]-b[stc[top]]);
			l+=len[top--];
		}
		f[i]=query(0,n,0,i-1,1);
		stc[++top]=i,len[top]=l;
		modify(0,n,i,i,1,f[i]-val[0]);
	}
	cout<<f[n]<<endl;
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();

	return 0;
}