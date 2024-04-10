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
const int N=400010;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
int a[N],t[N];
ll ans=0;
#define lb(x) (x&(-x))
struct BIT{
	ll t[N]; //
	void init(){
		mst(t,0);
	}
	void add(ll x,ll k){ //xk
		//x++;
		for(;x<N;x+=lb(x))
			t[x]+=k;
	}
	ll sum(ll x){ //[1,x] //[0,x]
		//x++;
		ll ans=0;
		for(;x!=0;x-=lb(x))
			ans+=t[x];
		return ans;
	}
}bit;
vector<int> b={0};
void disc(int a[],int n){
	repeat(i,0,n)b.push_back(a[i]),b.push_back(-a[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	repeat(i,0,n)
		a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1; //1
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n=read();
	repeat(i,0,n)a[i]=read();
	repeat(i,0,n)a[i]-=read();
	disc(a,n);
	int zero=lower_bound(b.begin(),b.end(),0)-b.begin()+1;
	//orzarr(a,n); cout<<zero<<endl;
	
	repeat(i,0,n){
		ans+=bit.sum(N-1)-bit.sum(2*zero-a[i]);
		bit.add(a[i],1);
	}
	cout<<ans<<endl;
	
	return 0;
}