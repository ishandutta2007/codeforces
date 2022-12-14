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
const int N=2000010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> vector<T> &operator<<(vector<T> &a,T b){a.push_back(b); return a;} template<typename T> T sqr(T x){return x*x;} void print(ll x,bool e=0){printf("%lld%c",x," \n"[e]);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
// #define int ll
pii v[N];
vector<array<int,3>> ans;
const int s=0,t=31;
void Solve(){
	int l=read(),r=read(); int top=1;
	repeat(i,1,21+1){
		top++;
		ans.push_back({s,i,1});
		repeat(j,1,i)
			ans.push_back({j,i,1<<(j-1)});
	}
	if(l==1){
		ans.push_back({s,t,1});
		l++;
	}
	int n=r-l+1;
	repeat_back(i,0,21)if((1<<i)<=n){
		ans.push_back({i+1,t,l-1});
		n-=(1<<i);
		l+=(1<<i);
	}
	printf("YES\n%d %d\n",32,(int)ans.size());
	for(auto i:ans)printf("%d %d %d\n",i[0]+1,i[1]+1,i[2]);
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; // T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}