#include <bits/stdc++.h>
using namespace std; //using namespace rel_ops;
#define lll __int128
#define inline __inline __attribute__((always_inline))
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}
#define fi first
#define se second
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
typedef double lf; typedef long double llf; const lf err=1e-11; const lf pi=acos(-1); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;}
typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=2520;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
#define LCM(x,y) (x/__gcd(x,y)*y)
ll dp[20][50][2521],m[2521],a[20];
ll dfs(int pos,int lcm,int num,int lim){
	if(pos==-1)return num%lcm==0;
	ll &x=dp[pos][m[lcm]][num];
	if(!lim && x!=-1)return x;
	ll ans=0;
	int maxi=lim?a[pos]:9;
	repeat(i,0,maxi+1){
		int nextlcm=i?LCM(lcm,i):lcm;
		int nextnum=(num*10+i)%2520;
		int nextlim=lim && i==maxi;
		ans+=dfs(pos-1,nextlcm,nextnum,nextlim);
	}
	if(!lim)x=ans;
	return ans;
}
ll solve(ll n){
	int len=0;
	while(n){
		a[len++]=n%10;
		n/=10;
	}
	return dfs(len-1,1,0,1);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cnt=0;
	repeat(i,1,2521)
	if(2520%i==0)
		m[i]=cnt++;
	mst(dp,-1);
	ll t=read();
	while(t--){
		ll l=read(),r=read();
		cout<<solve(r)-solve(l-1)<<endl;
	}
	return 0;
}