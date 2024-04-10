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
	const int mod=99824353;
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

const int N=1e3+5;
const int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};

int n,m,t,cnum,col[N][N],cov[N*N],ori[N*N];
char c[N][N];
vector <int> e[N*N];
ll dis[N*N];

int dfs(int x,int y,char z){
	col[x][y]=cnum; int sz=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx&&yy&&xx<=n&&yy<=m&&!col[xx][yy]&&c[xx][yy]==z)sz+=dfs(xx,yy,z);
	}
	return sz;
}

void solve(){
	cin>>n>>m>>t; queue <int> q; mem(dis,0x7f);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>c[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(!col[i][j]){
		ori[++cnum]=c[i][j]-'0'; int tmp=dfs(i,j,c[i][j]);
		if(tmp>1)q.push(cnum),cov[cnum]=cnum,dis[cnum]=0;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=0;k<4;k++){
		int ii=i+dx[k],jj=j+dy[k];
		if(ii&&jj&&ii<=n&&jj<=m&&col[i][j]!=col[ii][jj]){
			e[col[i][j]].pb(col[ii][jj]);
			e[col[ii][jj]].pb(col[i][j]);
		}
	}
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int it:e[t])if(!cov[it])cov[it]=cov[t],dis[it]=dis[t]+1,q.push(it);
	}
	while(t--){
		ll x,y,m; cin>>x>>y>>m; int c=col[x][y];
//		cout<<"check "<<dis[c]<<" "<<ori[c]<<endl;
		if(dis[c]>=m)cout<<ori[c]<<endl;
		else cout<<((m&1)^ori[cov[c]])<<endl;
	}
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}