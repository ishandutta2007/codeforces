//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
int a[N];
vector<array<int,3>> ans;
void work(int n){
	for(int i=0;i+2<n;i+=2){
		ans.push_back({i,i+1,i+2});
	}
	for(int i=n-5;i>=0;i-=2){
		ans.push_back({i,i+1,i+2});
	}
}
void print(){
	puts("YES");
	printf("%lld\n",(int)ans.size());
	for(auto i:ans)
		printf("%lld %lld %lld\n",i[0]+1,i[1]+1,i[2]+1);
}
void Solve(){
	int n=read();
	repeat(i,0,n)a[i]=read();
	if(n%2==1){
		work(n);
		print();
	}
	else{
		int s=accumulate(a,a+n,0,bit_xor<int>());
		if(s==0){
			work(n-3);
			ans.push_back({n-3,n-2,n-1});
			print();
		}
		else puts("NO");
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}