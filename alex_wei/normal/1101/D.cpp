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
	const int mod=1e9+7;
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

int n,ans;
map <int,int> mp[N];
vector <int> e[N];

void dfs(int id,int f){
	vector <pii> c;
	for(int to:e[id]){
		if(to==f)continue;
		dfs(to,id);
		for(pii it:mp[to]){
			int v=it.fi; c.pb(it);
			if(mp[id].find(v)!=mp[id].end())
				mp[id][v]=max(mp[id][v],it.se+1);
		}
	} sort(c.begin(),c.end());
	map <int,bool> ap;
	for(pii it:mp[id])ans=max(ans,it.se),ap[it.fi]=1;
	for(int i=1;i<c.size();i++)
		if(c[i-1].fi==c[i].fi&&ap[c[i].fi])
			ans=max(ans,c[i-1].se+c[i].se+1);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a; cin>>a;
		for(int j=2;j*j<=a;j++)
			while(a%j==0)mp[i][j]=ans=1,a/=j;
		if(a>1)mp[i][a]=ans=1;
	}
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		e[u].pb(v),e[v].pb(u);
	} dfs(1,0);
	cout<<ans<<endl;
	return 0; 
}
/*
input
5
2 2 3 3 3
1 2
1 3
3 4
3 5
output
3

input
5
6 6 3 3 3
1 2
1 3
3 4
3 5
output
4

input
7
3 3 3 3 3 3 3
1 2
1 3
2 4
2 5
3 6
3 7
output
5

input
7
1 3 3 3 3 3 3
1 2
1 3
2 4
2 5
3 6
3 7
output
3
*/