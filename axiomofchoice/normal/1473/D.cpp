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
char s[N];
int a[N],pre[N],lst[N];
int premax[N],premin[N],lstmax[N],lstmin[N];
void Solve(){
	int n=read(),m=read();
	scanf("%s",s);
	premax[0]=0,premin[0]=0;
	lstmax[n+1]=0,lstmin[n+1]=0; 
	lst[n+1]=0;
	repeat(i,1,n+1){
		a[i]=(s[i-1]=='+'?1:-1);
		pre[i]=pre[i-1]+a[i];
		premax[i]=max(premax[i-1],pre[i]);
		premin[i]=min(premin[i-1],pre[i]);
	}
	repeat_back(i,1,n+1){
		lst[i]=lst[i+1]+a[i];
		lstmax[i]=max(lstmax[i+1],lst[i]);
		lstmin[i]=min(lstmin[i+1],lst[i]);
	}
//	orzarr(pre+1,n);
//	orzarr(lst+1,n);
//	orzarr(premax+1,n);
//	orzarr(premin+1,n);
//	orzarr(lstmax+1,n);
//	orzarr(lstmin+1,n);
	while(m--){
		int l=read(),r=read();
		int u=premax[l-1],d=premin[l-1];
		int s=pre[l-1]+lst[r+1];
		u=max(u,-lstmin[r+1]+s);
		d=min(d,-lstmax[r+1]+s);
		printf("%d\n",u-d+1);
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}