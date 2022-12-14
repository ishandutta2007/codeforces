#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=500010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
int a[N],dp[N];
vector<int> pos;
int work(int a[],int n,int l,int r){
	//orzarr(a,n); orz(pii(l,r)); 
	if(l>r)return -1;
	fill(dp,dp+n+1,inf);
	repeat(i,0,n)
	if(a[i]>=l && a[i]<=r)
		*upper_bound(dp,dp+n,a[i])=a[i];
	return n-(lower_bound(dp,dp+n,inf)-dp);
}
void Solve(){
	int n=read(),m=read();
	repeat(i,1,n+1)a[i]=read()-i; a[0]=-inf,a[n+1]=inf;
	pos.push_back(0);
	repeat(i,0,m)pos.push_back(read());
	pos.push_back(n+1);
	int ans=0;
	repeat(i,0,pos.size()-1){
		int t=work(a+pos[i]+1,pos[i+1]-pos[i]-1,a[pos[i]],a[pos[i+1]]);
		if(t==-1){cout<<-1<<endl; return;}
		//orz(t);
		ans+=t;
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