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
	#ifdef __WIN64
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=getchar();
		while(!isdigit(s))sign|=s=='-',s=getchar();
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
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
	ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=2e5+5;
const int inf=0x3f3f3f3f;

int p[N],d[3][N]; ll pre[N];
vector <int> e[N];
queue <int> q;

void bfs(int id,int st){
	d[id][st]=0; q.push(st);
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int to:e[t])if(d[id][to]==inf)d[id][to]=d[id][t]+1,q.push(to);
	}
}

void solve(){
	int n,m,a,b,c; cin>>n>>m>>a>>b>>c;
	
	for(int i=1;i<=n;i++)d[0][i]=d[1][i]=d[2][i]=inf,e[i].clear();
	for(int i=1;i<=m;i++)cin>>p[i];
	sort(p+1,p+m+1);
	for(int i=1;i<=m;i++)pre[i]=pre[i-1]+p[i];
	
	for(int i=1;i<=m;i++){
		int u,v; cin>>u>>v;
		e[u].pb(v),e[v].pb(u);
	}
	bfs(0,a),bfs(1,b),bfs(2,c);
	
	ll ans=1e18;
	for(int i=1;i<=n;i++)if(d[0][i]+d[1][i]+d[2][i]<=m)
		ans=min(ans,pre[d[1][i]]+pre[d[0][i]+d[1][i]+d[2][i]]);
	cout<<ans<<endl;
}

int main(){
	int t; cin>>t;
	while(t--)solve();
	return 0;
}