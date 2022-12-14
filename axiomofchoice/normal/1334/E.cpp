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
const int N=300010; const double err=1e-11; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
const int mod=(0?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
int T,n,l,r,rr;
vector<int> d;
map<int,vector<int>> a;
struct CC{
	static const int N=1010;
	ll fac[N],inv[N];
	CC(){
		fac[0]=1;
		repeat(i,1,N)fac[i]=fac[i-1]*i%mod;
		inv[N-1]=qpow(fac[N-1],mod-2,mod);
		repeat_back(i,0,N-1)inv[i]=inv[i+1]*(i+1)%mod;
	}
}C;
void getdivisor(vector<int> &ans,int n){
	ans.assign(d.size(),0);
	repeat(i,0,d.size())
	while(n%d[i]==0)n/=d[i],ans[i]++;
}
vector<int> X,Y;
signed main(){
	int n=read(),q=read();
	for(int i=2;i*i<=n;i++){
		if(n%i==0)d.push_back(i);
		while(n%i==0)n/=i;
	}
	if(n>1)d.push_back(n);
	//orzeach(d);
	while(q--){
		int x=read(),y=read();
		getdivisor(X,x);
		getdivisor(Y,y);
		
		int ans1=1,ans2=1,sum=0;
		repeat(i,0,d.size())
		if(X[i]>Y[i])
			ans2=ans2*C.inv[abs(X[i]-Y[i])]%mod,
			sum+=abs(X[i]-Y[i]);
		ans1=ans1*C.fac[sum]%mod;
		
		sum=0;
		repeat(i,0,d.size())
		if(X[i]<Y[i])
			ans2=ans2*C.inv[abs(X[i]-Y[i])]%mod,
			sum+=abs(X[i]-Y[i]);
		ans1=ans1*C.fac[sum]%mod;
		
		cout<<ans1*ans2%mod<<endl;
	}
	return 0;
}