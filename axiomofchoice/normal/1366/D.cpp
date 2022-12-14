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
const int N=10000010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<ll,ll> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
int a[N],rec[N]; bool vis[N];
//a[i]i+1vis[i]==0i
void get_prime(int n){
	int cnt=0; vis[1]=1;
	repeat(i,2,n+1){
		if(!vis[i]) //
			a[cnt++]=i,rec[i]=i; //
		repeat(j,0,cnt){
			if(i*a[j]>n)break;
			if(vis[i*a[j]]==0){
				vis[i*a[j]]=1;
				rec[i*a[j]]=a[j];
			}
			if(i%a[j]==0)break;
		}
	}
}
vector<pii> ans;
signed main(){
	get_prime(N-1);
	int n; cin>>n; 
	while(n--){
		int x; cin>>x;
		int p=rec[x],y=1;
		if(p>1)while(x%p==0)x/=p,y*=p;
		if(x>1 && y>1)
			ans.push_back({x,y});
		else ans.push_back({-1,-1});
	}
	for(auto i:ans)cout<<i.first<<' '; cout<<endl;
	for(auto i:ans)cout<<i.second<<' '; cout<<endl;
	return 0;
}