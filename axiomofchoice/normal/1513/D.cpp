// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
// int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> vector<T> &operator<<(vector<T> &a,T b){a.push_back(b); return a;} template<typename T> T sqr(T x){return x*x;} void print(ll x,bool e=0){printf("%lld%c",x," \n"[e]);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
// #define int ll
ll A[N];
struct ST{
	#define logN 21
	int U(int x,int y){return A[x]<A[y]?x:y;}
	int a[N][logN];
	void init(int n){
		repeat(i,0,n)
			a[i][0]=i;
		repeat(k,1,logN)
		repeat(i,0,n-(1<<k)+1)
			a[i][k]=U(a[i][k-1],a[i+(1<<(k-1))][k-1]);
	}
	int query(int l,int r){
		int s=31-__builtin_clz(r-l+1);
		return U(a[l][s],a[r-(1<<s)+1][s]);
	}
}st;
ll ans,p,n;
void work(int l,int r){
	int m=st.query(l,r);
	int x=m,y=m;
	while(x!=l && A[x-1]%A[m]==0)x--;
	while(y!=r && A[y+1]%A[m]==0)y++;
	ans+=1ll*(y-x)*min(p,A[m]);
	if(x!=l)work(l,x-1),ans+=p;
	if(x==l && l!=0 && A[x-1]%A[m]==0 && A[m]<p)ans+=A[m]-p;
	if(y!=r)work(y+1,r),ans+=p;
	if(y==r && r!=n-1 && A[y+1]%A[m]==0 && A[m]<p)ans+=A[m]-p;
}
void Solve(){
	n=read(); p=read(); ans=0;
	repeat(i,0,n)A[i]=read();
	st.init(n);
	work(0,n-1);
	print(ans,1);
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}