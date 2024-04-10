#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
#define fi first
#define se second
#ifndef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<ll,ll> pii;
int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
int k;
vector<int> a;
void Solve(){
	cin>>k;
	a.assign(10,1); int s=1;
	repeat(i,0,inf){
		if(s>=k)break;
		i%=10;
		s/=a[i];
		a[i]++;
		s*=a[i];
	}
	repeat(i,0,a[0])cout<<'c';
	repeat(i,0,a[1])cout<<'o';
	repeat(i,0,a[2])cout<<'d';
	repeat(i,0,a[3])cout<<'e';
	repeat(i,0,a[4])cout<<'f';
	repeat(i,0,a[5])cout<<'o';
	repeat(i,0,a[6])cout<<'r';
	repeat(i,0,a[7])cout<<'c';
	repeat(i,0,a[8])cout<<'e';
	repeat(i,0,a[9])cout<<'s';
	cout<<endl;
}
signed main(){
	int T=1; //cin>>T;
	while(T--)Solve();
	return 0;
}