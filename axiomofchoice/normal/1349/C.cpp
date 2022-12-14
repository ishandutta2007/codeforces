#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
#define vector basic_string
#define fi first
#define se second
#ifndef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=1010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
int T,n,m,Q;
ll dis[N][N],ans;
string s[N];
queue<pii> q;
const int dn[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void push0(int x,int y){
	if(dis[x][y]==INF){
		q.push({x,y});
		dis[x][y]=0;
	}
}
signed main(){
	cin>>n>>m>>Q;
	repeat(i,0,n)cin>>s[i];
	repeat(i,0,n)repeat(j,0,m)dis[i][j]=INF;
	repeat(i,0,n)
	repeat(j,0,m){
		if(i!=n-1 && s[i][j]==s[i+1][j])
			push0(i,j),push0(i+1,j);
		if(j!=m-1 && s[i][j]==s[i][j+1])
			push0(i,j),push0(i,j+1);
	}
	while(!q.empty()){
		int x=q.front().fi,y=q.front().se;
		q.pop();
		repeat(i,0,4){
			int px=x+dn[i][0],py=y+dn[i][1];
			if(px>=0 && py>=0 && px<n && py<m)
			if(dis[px][py]==INF){
				dis[px][py]=dis[x][y]+1;
				q.push({px,py});
			}
		}
	}
	repeat(i,0,Q){
		ll x,y,p;
		cin>>x>>y>>p;
		x--,y--;
		if(p<=dis[x][y])
			cout<<s[x][y]<<endl;
		else
			cout<<char(s[x][y]^((p-dis[x][y])%2))<<endl;
	}
	return 0;
}