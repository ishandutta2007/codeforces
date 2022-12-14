//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=110; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
bool a[N][N];
vector<int> ans;
void opt(int x,int y){
	ans<<x; ans<<y;
	a[x][y]^=1;
}
void Solve(){
	int n=read(),m=read(); ans.clear();
	repeat(i,0,n){
		static char s[N];
		scanf("%s",s);
		repeat(j,0,m)
			a[i][j]=s[j]=='1';
	}
	repeat_back(i,2,n)
	repeat(j,0,m)
	if(a[i][j]){
		opt(i,j); opt(i-1,j);
		opt(i-1,(j+1!=m?j+1:j-1));
	}
	n=2;
	repeat_back(j,2,m)
	repeat(i,0,n)
	if(a[i][j]){
		opt(i,j); opt(i,j-1);
		opt((i+1!=n?i+1:i-1),j-1);
	}
	m=2;
	if(a[0][0]+a[0][1]+a[1][0]+a[1][1]==4){
		opt(0,0),opt(0,1),opt(1,0);
	}
	if(a[0][0]+a[0][1]+a[1][0]+a[1][1]==1){
		if(a[0][0])
			opt(0,0),opt(0,1),opt(1,0);
		else
			opt(0,1),opt(1,0),opt(1,1);
	}
	if(a[0][0]+a[0][1]+a[1][0]+a[1][1]==2){
		bool f=1;
		repeat(i,0,2)
		repeat(j,0,2)
		if(f && a[i][j]){
			repeat(ii,0,2)
			repeat(jj,0,2)
			if(i!=ii || j!=jj)
				opt(ii,jj);
			f=0;
		}
	}
	if(a[0][0]+a[0][1]+a[1][0]+a[1][1]==3){
		repeat(i,0,2)
		repeat(j,0,2)
		if(a[i][j])
			opt(i,j);
	}
	printf("%d\n",(int)ans.size()/6);
	for(int i=0;i<(int)ans.size();i+=6){
		repeat(j,0,6)printf("%d ",ans[i+j]+1);
		puts("");
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}