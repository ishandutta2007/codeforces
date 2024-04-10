#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=300010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(0?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
struct CC{
	static const int N=300010;
	ll fac[N],inv[N];
	CC(){
		fac[0]=1;
		repeat(i,1,N)fac[i]=fac[i-1]*i%mod;
		inv[N-1]=qpow(fac[N-1],mod-2,mod);
		repeat_back(i,1,N)inv[i-1]=inv[i]*i%mod;
	}
	ll operator()(ll a,ll b){ //a>=b
		if(a<b || b<0)return 0;
		return fac[a]*inv[a-b]%mod*inv[b]%mod;
	}
	ll A(ll a,ll b){ //a>=b
		if(a<b || b<0)return 0;
		return fac[a]*inv[a-b]%mod;
	}
}C;
vector<pii> a;
void Solve(){
	int n=read(),k=read();
	repeat(i,0,n){
		int x=read(),y=read();
		a<<pii(x,1);
		a<<pii(y+1,-1);
	}
	sort(a.begin(),a.end());
	int cnt=0,ans=0;
	for(auto i:a){
		if(i.se==-1){
			cnt--;
		}
		else{
			if(cnt>=k-1){
				ans+=C(cnt,k-1);
				ans>=mod?ans-=mod:0;
			}
			cnt++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}