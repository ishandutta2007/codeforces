/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;
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

const int N=5e5+5;
const int M=2e5+5;

int n,m,q,p[M],del[M];
int op[N],v[N],qu[N];
int x[N],y[N],vis[N];

int f[M],to[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
set <int> s[M];
vector <int> ins[N];

int main(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)p[i]=read(),f[i]=i;
	for(int i=1;i<=m;i++)x[i]=read(),y[i]=read();
	for(int i=1;i<=q;i++){
		op[i]=read(),v[i]=read();
		if(op[i]==2)vis[v[i]]=1;
	}
	for(int i=1;i<=m;i++)
		if(!vis[i]){
			int xx=x[i],yy=y[i],fx=find(xx),fy=find(yy);
			if(fx!=fy)f[fx]=fy;
		} int cnt=n;
	
	for(int i=1;i<=n;i++){
		f[i]=find(f[i]);
		s[f[i]].insert(p[i]);
	}
	for(int i=q;i;i--){
		if(op[i]==2){
			int xx=x[v[i]],yy=y[v[i]];
			int fx=find(xx),fy=find(yy);
			if(fx!=fy){
				if(s[fx].size()<s[fy].size())swap(fx,fy);
				for(int it:s[fy])s[fx].insert(it),ins[i].pb(it);
				to[i]=fx,f[fy]=fx;
			}
		} else qu[i]=find(v[i]); 
	}
	for(int i=1;i<=q;i++) if(op[i]==1){
		int z=qu[i],ok=0;
		if(s[z].size()){
			for(auto it=s[z].end();;){
				if(it==s[z].end())it--;
				bool first=(it==s[z].begin());
				if(del[*it]){
					auto tmp=it; it--;
					s[z].erase(tmp);
				}
				else{
					del[*it]=ok=1;
					printf("%d\n",*it);
					break;
				}
				if(first)break;
			}
		}
		if(!ok)puts("0");
	} else {
		int v=to[i];
		for(int it:ins[i]){
			auto c=s[v].find(it);
			if(c!=s[v].end())s[v].erase(c);
		}
	}
	return 0;
}