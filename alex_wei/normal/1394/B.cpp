/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize(3)
//#define int long long

#define ll long long
#define pii pair <int,int>
#define pll pair <ll,ll>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

// Templates start.

namespace IO {
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read() {
		int x=0,sign=0; char s=gc;
		while(!isdigit(s)) sign|=s=='-',s=gc;
		while(isdigit(s)) x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math {
	const int mod=1e9+7;
	const int maxn=1e6+5;

	ll ksm(ll a,ll b) {ll s=1,m=a; while(b) {if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
	ll inv(ll x) {return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n) {
		fc[0]=1;
		for(int i=1;i<=n;i++) fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--) ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll C(ll n,ll m) {return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}


// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=3e5+5;

int n,m,k,vs[10][10],e[10][10][10][10];
vector <pii> f[N],rf[N];
pii p[N]; 

int ans,c[10];
void dfs(int num){
	if(num>k){
		bool pd=1;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++)
				if(e[i][c[i]][j][c[j]])
					pd=0;
		ans+=pd;
		return;
	}
	for(int i=1;i<=num;i++)
		c[num]=i,dfs(num+1);
}

void solve(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		f[u].pb((pii){w,v});
		rf[v].pb((pii){w,u});
	}
	for(int i=1;i<=n;i++)if(!f[i].size())puts("0"),exit(0);
	for(int i=1;i<=n;i++)if(!rf[i].size())puts("0"),exit(0);
	for(int i=1;i<=n;i++)sort(f[i].begin(),f[i].end());
	for(int i=1;i<=n;i++){
		mem(vs,0);
		for(int j=0;j<rf[i].size();j++){
			pii v=rf[i][j];
			int u=v.se,c=lower_bound(f[u].begin(),f[u].end(),(pii){v.fi,i})-f[u].begin()+1;
			p[j]={f[u].size(),c};
			if(vs[f[u].size()][c])e[f[u].size()][c][f[u].size()][c]=1;
			vs[f[u].size()][c]=1;
		}
		sort(p,p+rf[i].size());
		int cnt=unique(p,p+rf[i].size())-p;
		for(int j=0;j<cnt;j++)
			for(int k=0;k<cnt;k++)
				if(j!=k) e[p[j].fi][p[j].se][p[k].fi][p[k].se]=1;
	}
	dfs(1),cout<<ans<<endl;
}

int main() {
	int t=1;
//	cin>>t;
	while(t--)solve();

	return 0;
}