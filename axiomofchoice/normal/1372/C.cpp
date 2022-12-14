#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#define endl "\n"
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<int,int> pii;
const int mod=(999983); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
int a[N];
void Solve(){
	int n=read();
	repeat(i,0,n){
		a[i]=read()==i+1;
	}
	a[n]=1; int cnt=0;
	repeat(i,0,n)
	if(!a[i] && a[i+1])
		cnt++;
	if(*min_element(a,a+n)==1)cout<<0<<endl;
	else if(cnt==1)cout<<1<<endl;
	else cout<<2<<endl;
}
signed main(){
	int T=1; T=read();
	while(T--)Solve();
	return 0;
}