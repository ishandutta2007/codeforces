//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=400010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
#define sortunique(a) ({sort(a.begin(),a.end()); a.erase(unique(a.begin(),a.end()),a.end());})
pii a[N];
#define lb(x) (x&(-x))
struct BIT{
	int t[N]; //?????
	void init(int n){
		fill(t,t+n+1,0);
	}
	void add(int x,int k){ //??x??k
		x++;
		for(;x<N;x+=lb(x))
			t[x]+=k;
	}
	int sum(int x){ //?[1,x]?? //[0,x]
		x++;
		ll ans=0;
		for(;x!=0;x-=lb(x))
			ans+=t[x];
		return ans;
	}
}bit,bit2;
vector<int> b;
void Solve(){
	int n=read();
	b.clear();
	repeat(i,0,n){
		a[i].fi=read(),a[i].se=read();
		b.push_back(a[i].fi);
		b.push_back(a[i].se);
	}
	sortunique(b);
	repeat(i,0,n){
		a[i].fi=lower_bound(b.begin(),b.end(),a[i].fi)-b.begin()+1;
		a[i].se=lower_bound(b.begin(),b.end(),a[i].se)-b.begin()+1;
	}
	bit.init(2*n+5);
	bit2.init(2*n+5);
	repeat(i,0,n){
		bit.add(a[i].fi,1);
		bit.add(a[i].se+1,-1);
		bit2.add(a[i].se,1);
	}
	int ans=0;
	repeat(i,0,n){
		ans=max(ans,bit.sum(a[i].se)+bit2.sum(a[i].se-1)-bit2.sum(a[i].fi-1));
	}
	printf("%d\n",n-ans);
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}