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
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
string s;
int ss[4]={0,2,3,1};
int f(int x){
	if(x==0)return 0;
	return f(x/4)*4+ss[x%4];
}
signed main(){
	int T=read();
	while(T--){
		int n=read()-1; if(n<3){cout<<n+1<<endl; continue;}
		int p=n/3;
		int x;
		for(x=1;p>=0;p-=x,x*=4);
		x/=4; p+=x;
		if(n%3==0){cout<<p+x<<endl; continue;}
		int t1=x+p;
		int t2=f(t1);
		if(n%3==1)cout<<t2<<endl;
		else cout<<(t1^t2)<<endl;
	}
	return 0;
}