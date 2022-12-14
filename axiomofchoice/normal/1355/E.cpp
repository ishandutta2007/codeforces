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
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
int n,A,B,C;
int a[N];
int get_cost(int h){
	int up=0,down=0;
	repeat(i,0,n)
		(h>a[i]?up:down)+=abs(a[i]-h);
	int t=min(up,down);
	return (up-t)*A+t*B+(down-t)*C;
}
signed main(){
	cin>>n>>A>>C>>B; B=min(B,A+C);
	repeat(i,0,n)
		cin>>a[i];
	int l=0,r=1e9+1;
	while(l<r){
		int x=(l+r)/2,y=x+1;
		if(get_cost(x)<get_cost(y))
			r=y-1;
		else
			l=x+1;
	}
	cout<<get_cost(l)<<endl;
	return 0;
}