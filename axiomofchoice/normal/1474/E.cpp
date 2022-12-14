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
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
void Solve(){
	int n=read();
	vector<int> a(n); vector<pii> ans;
	iota(a.begin(),a.end(),0);
	int dif=n-1; ll tot=0;
	repeat(cnt,1,n){
		if(cnt%2==0)swap(a[0],a[dif]),ans.push_back({dif,0});
		else swap(a[n-1-dif],a[n-1]),ans.push_back({n-1-dif,n-1});
		tot+=1ll*dif*dif;
		if(cnt%2==1)dif--;
	}
	printf("%lld\n",tot);
	reverse(ans.begin(),ans.end());
	for(auto i:a)printf("%d ",i+1);
	puts("");
	printf("%d\n",n-1);
	for(auto i:ans)printf("%lld %lld\n",i.fi+1,i.se+1);
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}