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

int n,q,a[N],val[N<<2],tag[N<<2],ans[N];

struct query{
	int x,y,id;
	bool operator < (const query &v) const {
		return x>v.x;
	}
}c[N];

void push(int x){
	if(tag[x]){
		val[x<<1]-=tag[x];
		val[x<<1|1]-=tag[x];
		tag[x<<1]+=tag[x];
		tag[x<<1|1]+=tag[x];
		tag[x]=0;
	}
}

void add(int l,int r,int pos,int x,int v){
	if(l==r){
		val[x]=v;
		return;
	} int m=l+r>>1; push(x);
	if(pos<=m)add(l,m,pos,x<<1,v);
	else add(m+1,r,pos,x<<1|1,v);
	val[x]=min(val[x<<1],val[x<<1|1]);
}

int querypos(int l,int r,int p,int x){
	if(l==r&&val[x]>0)return 1e9;
	if(l==r&&val[x]==0)return l;
	int m=l+r>>1,ans; push(x);
	if(m<p)ans=querypos(m+1,r,p,x<<1|1);
	else if(val[x<<1|1]==0)ans=querypos(m+1,r,p,x<<1|1);
	else ans=querypos(l,m,p,x<<1);
	val[x]=min(val[x<<1],val[x<<1|1]);
	return ans;
}

void modify(int l,int r,int ql,int qr,int x){
	if(ql>qr)return;
	if(ql<=l&&r<=qr){
		val[x]--,tag[x]++;
		return;
	} int m=l+r>>1; push(x);
	if(ql<=m)modify(l,m,ql,qr,x<<1);
	if(m<qr)modify(m+1,r,ql,qr,x<<1|1);
	val[x]=min(val[x<<1],val[x<<1|1]);
}

int d[N];
void add(int x){while(x<=n)d[x]++,x+=x&-x;}
int query(int x){int ans=0; while(x)ans+=d[x],x-=x&-x; return ans;}

void solve(){
	cin>>n>>q; mem(val,0x3f);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=q;i++)cin>>c[i].x>>c[i].y,c[i].id=i;
	sort(c+1,c+q+1);
	int p=1; 
	for(int i=n;i;i--){
		add(1,n,i,1,a[i]>i?1e9:i-a[i]);
		while(val[1]==0){
			int pos=querypos(1,n,i,1);
			add(pos),add(1,n,pos,1,1e9),modify(1,n,pos+1,n,1);
		}
		while(p<=q&&c[p].x==i-1){
			ans[c[p].id]=query(n-c[p].y);
			p++;
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
}


int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}