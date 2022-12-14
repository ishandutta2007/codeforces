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
const int N=2010;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
int n,h,l,r;
vector<int> now(N),past(N);
int jg(int x){return l<=x && x<=r;}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>h>>l>>r;
	repeat(j,0,h)
		now[j]=-inf;
	now[0]=0;
	repeat(i,1,n+1){
		swap(now,past);
		repeat(j,0,h)
			now[j]=-inf;
		int x;
		cin>>x;
		repeat(j,0,h){
			#define MAX(x,y) x=max(x,y)
			MAX(now[(j+x-1)%h],past[j]+jg((j+x-1)%h));
			MAX(now[(j+x)%h],past[j]+jg((j+x)%h));
		}
	}
	int ans=0;
	repeat(i,0,h)ans=max(ans,now[i]);
	cout<<ans<<endl;
	return 0;
}