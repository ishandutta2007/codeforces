#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=2010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
char s[N][N];
int f(int x,int y){
	return s[x][y]=='.';
}
queue<pii> q;
void Solve(){
	int n=read(),m=read();
	repeat(i,1,n+1)scanf("%s",s[i]+1);
	repeat(i,0,n+2)s[i][0]=s[i][m+1]='*';
	repeat(j,0,m+2)s[0][j]=s[n+1][j]='*';
	//repeat(i,0,n+2)puts(s[i]);
	repeat(i,1,n+1)
	repeat(j,1,m+1)
	if(s[i][j]=='.')
		q.push({i,j});
	while(!q.empty()){
		int x=q.front().fi,y=q.front().se; q.pop();
		for(auto dx:{-1,1})
		for(auto dy:{-1,1}){
			int cnt=0;
			repeat(i,0,2)
			repeat(j,0,2)
				cnt+=f(x+i*dx,y+j*dy);
			if(cnt==3)
			repeat(i,0,2)
			repeat(j,0,2)
			if(!f(x+i*dx,y+j*dy)){
				s[x+i*dx][y+j*dy]='.';
				q.push({x+i*dx,y+j*dy});
			}
		}
	}
	repeat(i,1,n+1){
		repeat(j,1,m+1)
			putchar(s[i][j]);
		puts("");
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}