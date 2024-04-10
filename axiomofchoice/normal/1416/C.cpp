#pragma GCC optimize("Ofast")
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
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
int a[N],b[N]; ll ans,anss;
ll sum[2][32];
void merge(int l,int r,int bit,int Bit){//orz(bit);
	if(l+1>=r || bit==0)return; 
	int cnt0=0,cnt1=0;
	repeat(i,l,r){
		if(a[i]&bit)cnt0++,sum[1][Bit]+=cnt1;
		else sum[0][Bit]+=cnt0,cnt1++;
	}
	int p=l;
	repeat(i,l,r)if(~a[i]&bit)b[p++]=a[i];
	int m=p;
	repeat(i,l,r)if(a[i]&bit)b[p++]=a[i];
	repeat(i,l,r)a[i]=b[i];
	merge(l,m,bit>>1,Bit-1);
	merge(m,r,bit>>1,Bit-1);
}
void Solve(){
	int n=read();
	repeat(i,0,n){
		a[i]=read();
	}
	merge(0,n,1<<30,30);
	repeat(i,0,31){
		if(sum[0][i]>sum[1][i])
			anss^=1<<i;
		ans+=min(sum[0][i],sum[1][i]);
	}
	cout<<ans<<' '<<anss<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}