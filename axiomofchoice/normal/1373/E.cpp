#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#define endl "\n"
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int __int128
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>=10)write(x/10);
	putchar(x%10^48);
}
int ans,n,k;
int getnum(int n){ //n
	int ans=n%9;
	repeat(i,0,n/9)ans=ans*10+9;
	return ans;
}
void Solve(){
	n=read(),k=read(); ans=1e30;
	repeat(i,0,100)if(i+k<100){
		int sum=0;
		repeat(j,i,i+k+1)sum+=j/10+j%10;
		if(n-sum>=0 && (n-sum)%(k+1)==0)
			ans=min(ans,getnum((n-sum)/(k+1))*100+i);
	}
	write(ans==1e30?-1:ans); puts("");
}
signed main(){
	int T=read();
	while(T--)Solve();
	return 0;
}