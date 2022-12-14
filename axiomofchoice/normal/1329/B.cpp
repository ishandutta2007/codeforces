#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define vector basic_string
#define fi first
#define se second
#ifndef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010; const double err=1e-11; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
ll p[32],dp[32][32],t,d,m;
signed main(){
	cin>>t;
	while(t--){
		cin>>d>>mod;
		p[0]=1; repeat(i,1,32)p[i]=p[i-1]*2%mod;
		repeat(num,0,32){
			if(num==0)
			repeat(i,num,32)
				dp[num][i]=1;
			else
			repeat(i,num,32)
				dp[num][i]=(dp[num][i-1]+dp[num-1][i-1]*p[i-1]%mod);
		}
		//repeat(i,0,16)
			//orzarr(dp[i],16);
		int s=1,k=1;
		while(s<=d)s<<=1,k++;
		s>>=1,k--;//orz(s);orz(k);
		ll ans=0;
		repeat(i,0,k)ans+=(d-s+1)*dp[i][k-1]%mod;
		repeat(i,1,k)ans+=dp[i][k-1];
		cout<<ans%mod<<endl;
	}
	return 0;
}