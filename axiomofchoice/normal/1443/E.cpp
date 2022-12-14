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
int *decantor(int x,int n){
	static int f[16]={1};
	repeat(i,1,16)f[i]=f[i-1]*i;
	static int ans[N];
	static set<int> s; s.clear();
	//x--;
	repeat(i,1,n+1)s.insert(i);
	repeat(i,0,n){
		int q=x/f[n-i-1];
		x%=f[n-i-1];
		auto it=s.begin();
		repeat(i,0,q)it++; //q+1
		ans[i]=*it;
		s.erase(it);
	}
	return ans;
}
ll q1(int l,int r,int n){
	r=min(r,n); l--;
	if(l>r)return 0;
	return r*(r+1)/2-l*(l+1)/2;
}
ll q2(int l,int r,int n,int n2,int step){
	int *a=decantor(step,n2)-(n-n2+1);
	//orzarr(a+1,n);
	l=max(l,n-n2+1); //orz(l); orz(r);
	ll ans=0;
	repeat(i,l,r+1)ans+=a[i]+(n-n2);
	return ans;
}
void Solve(){
	int n=read(),q=read(),step=0;
	int n2=min(15ll,n),n1=n-n2;
	while(q--){
		int op=read();
		if(op==1){
			int l=read(),r=read();
			ll ans=q1(l,r,n1)+q2(l,r,n,n2,step);
			printf("%lld\n",ans);
		}
		else step+=read();
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