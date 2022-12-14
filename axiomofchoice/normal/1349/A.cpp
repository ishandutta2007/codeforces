#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
int T=448,n,ans=1;
int a[N],f[32];
signed main(){
	cin>>n;
	repeat(i,0,n)
		cin>>a[i];
	repeat(t,2,T){ //Tsqrt(200000)
		int MN=INF,mn=INF;
		repeat(i,0,n){
			int p=1;
			while(a[i]%t==0){
				a[i]/=t;
				p*=t;
			}
			if(p<MN){mn=MN; MN=p;}
			else if(p<mn)mn=p;
		}
		if(mn!=INF)ans*=mn;
	}
	//sqrt(200000)
	map<int,int> m;
	repeat(i,0,n)
	if(a[i]>1){
		m[a[i]]++;
	}
	for(auto i:m){
		if(i.second>=n-1)ans*=i.first;
	}
	cout<<ans<<endl;
	return 0;
}