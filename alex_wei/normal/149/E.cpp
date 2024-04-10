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
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))
#define mcpy(x,y) memcpy(x,y,sizeof(y))

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
	const int mod=99824353;
	const int maxn=1e6+5;
	
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

// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=1e5+5;
const int P=1000+5;
const int K=17;

int n,q;
struct SA{
	char s[N],p[P];
	int sa[N],rk[N],pre[N],mi[N][K];
	int ork[N],buc[N],id[N],px[N];
	bool cmp(int a,int b,int w){
		return ork[a]==ork[b]&&ork[a+w]==ork[b+w];
	}
	void build(){
		int m=128,p=0;
		for(int i=1;i<=n;i++)buc[rk[i]=s[i]]++;
		for(int i=1;i<=m;i++)buc[i]+=buc[i-1];
		for(int i=n;i;i--)sa[buc[rk[i]]--]=i;
		for(int w=1;w<n;w<<=1,m=p,p=0){
			for(int i=n;i>n-w;i--)id[++p]=i;
			for(int i=1;i<=n;i++)if(sa[i]>w)id[++p]=sa[i]-w;
			for(int i=1;i<=m;i++)buc[i]=0;
			for(int i=1;i<=n;i++)buc[px[i]=rk[id[i]]]++;
			for(int i=1;i<=m;i++)buc[i]+=buc[i-1];
			for(int i=n;i;i--)sa[buc[px[i]]--]=id[i];
			mcpy(ork,rk),p=0;
			for(int i=1;i<=n;i++)rk[sa[i]]=cmp(sa[i],sa[i-1],w)?p:++p;
			if(p==n)break;
		} for(int i=0;i<K;i++)
			for(int j=1;j+(i==0?0:1<<i-1)<=n;j++)
				if(i)mi[j][i]=min(mi[j][i-1],mi[j+(1<<i-1)][i-1]);
				else mi[j][i]=sa[j];
	}
	int gmin(int l,int r){
		int k=log2(r-l+1);
		return min(mi[l][k],mi[r-(1<<k)+1][k]);
	}
	void run(){
		int l=1,r=n;
		for(int i=1;i<=q;i++){
			int nl=l,nr=r+1;
			while(nl<nr){
				int m=nl+nr>>1; 
				if(sa[m]+i-1>n)nl=m+1;
				else if(p[i]<=s[sa[m]+i-1])nr=m;
				else nl=m+1;
			} l=nl,nr=r+1;
			while(nl<nr){
				int m=nl+nr>>1;
				if(sa[m]+i-1>n)nl=m+1;
				else if(p[i]>=s[sa[m]+i-1])nl=m+1;
				else nr=m;
			} r=--nr;
			if(l>r){
				for(int j=i;j<=q;j++)pre[j]=-1;
				return;
			} pre[i]=gmin(l,r)+i-1;
		}
	}
}sa,sb;

int m,ans;
int main(){
	scanf("%s",sa.s+1),n=strlen(sa.s+1);
	for(int i=1;i<=n;i++)sb.s[i]=sa.s[n-i+1];
	sa.build(),sb.build(),cin>>m;
	for(int i=1;i<=m;i++){
		scanf("%s",sa.p+1),q=strlen(sa.p+1);
		for(int i=1;i<=q;i++)sb.p[i]=sa.p[q-i+1];
		sa.run(),sb.run();
		for(int i=1;i<q;i++)
			if(~sa.pre[i]&&~sb.pre[q-i]&&sa.pre[i]<n-sb.pre[q-i]+1){
				ans++; break;
			}
	} cout<<ans<<endl;
	return 0;
}