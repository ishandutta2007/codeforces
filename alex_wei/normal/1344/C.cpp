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

int n,m,top,dnum,tag[N],sta[N],dfn[N],low[N],vis[N];
vector <int> e[N],re[N];

void dfs(int id){
	dnum++;
	dfn[id]=low[id]=dnum;
	sta[++top]=id;
	vis[id]=1;
	for(auto to:e[id]){
		if(!dfn[to]){
			dfs(to);
			low[id]=min(low[id],low[to]);
		}
		else if(vis[to])low[id]=min(low[id],low[to]);
	}
	if(dfn[id]==low[id]){
		vis[id]=0;
		int cnt=0;
		while(sta[top]!=id)puts("-1"),exit(0);
		top--;
	}
}

int ans,v[N],rv[N],d[N],rd[N],tmp[N],rtmp[N];

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y,d[y]++,rd[x]++;
		e[x].pb(y); re[y].pb(x);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
	queue <int> q;
	for(int i=1;i<=n;i++)if(!d[i])q.push(i);
	for(int i=1;i<=n;i++)v[i]=rv[i]=i;
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int it:e[t]){
			d[it]--,v[it]=min(v[it],v[t]);
			if(!d[it])q.push(it);
		}
	}
	for(int i=1;i<=n;i++)if(!rd[i])q.push(i),rv[i]=i;
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int it:re[t]){
			rd[it]--,rv[it]=min(rv[it],rv[t]);
			if(!rd[it])q.push(it);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(v[i]>=i&&rv[i]>=i)cnt++;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)if(v[i]>=i&&rv[i]>=i)cout<<'A'; else cout<<'E';
	
	return 0;
}