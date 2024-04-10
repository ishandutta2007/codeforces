#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
//#define endl "\n"
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=30; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
int n,a[N][N];
pii g[N][N];
vector<pii> ans;
void Solve(){
	int n=read();
	a[0][0]=0;
	g[0][0]=pii(0,0);
	repeat(sum,1,n*2-1){
		int pre=-1;
		repeat(j,0,n)
		repeat(i,0,n)
		if(i+j==sum){
			int mn=INF,mx=-INF;
			if(i)mn=min(mn,g[i-1][j].fi),mx=max(mx,g[i-1][j].se);
			if(j)mn=min(mn,g[i][j-1].fi),mx=max(mx,g[i][j-1].se);
			g[i][j]={pre+1,pre+1+mx-mn};
			a[i][j]=g[i][j].fi-mn;
			pre=pre+1+mx-mn;
		}
	}
//	repeat(i,0,n){
//		repeat(j,0,n)
//			cout<<g[i][j]<<' ';
//		cout<<endl;
//	}
	repeat(i,0,n){
		repeat(j,0,n)
			printf("%lld ",a[i][j]);
		puts("");
	}
	fflush(stdout);
	int q=read();
	while(q--){
		ans.clear();
		int s=read(); int x=n-1,y=n-1; ans<<pii(x,y);
		while(x || y){
			if(!x)y--;
			else if(!y)x--;
			else{
				s-=a[x][y];
				if(g[x-1][y].fi<=s && g[x-1][y].se>=s)
					x--;
				else y--;
			}
			ans<<pii(x,y);
		}
		repeat_back(i,0,ans.size())
			printf("%lld %lld\n",ans[i].fi+1,ans[i].se+1);
		fflush(stdout);
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	while(T--)Solve();
	return 0;
}