//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll; typedef double lf; typedef pair<ll,ll> pii;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0); ll read(); lf readf();
const int inf=~0u>>2; const ll INF=~0ull>>2; const lf pi=acos(-1.0);
template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const int N=200010; const ll mod=(1?1000000007:998244353); ll mul(ll,ll,ll); ll qpow(ll,ll,ll);
#define int ll
vector<int> stk;
int a[N],ans[N];
void Solve(){
	int n=read(); stk.clear();
	repeat(i,0,n){
		a[i]=read(); stk<<i;
		if(stk.size()>=2 && a[stk.rbegin()[0]]==a[stk.rbegin()[1]])
			stk.pop_back(),stk.pop_back();
	}
	fill(ans,ans+n,1);
	if(stk.size()==2)
		for(auto i:stk)ans[i]=!a[i];
	else if(stk.size()>=2)ans[stk[1]]=0;
	repeat(i,3,stk.size())if(a[stk[i]])ans[stk[i]]=0;
	cout<<accumulate(ans,ans+n,0)<<endl;
	repeat(i,0,n)if(ans[i])cout<<a[i]<<' ';
	cout<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}
ll read(){
	ll x; if(scanf("%lld",&x)==-1)exit(0);
	return x;
}
lf readf(){
	lf x; if(scanf("%lf",&x)==-1)exit(0);
	return x;
}
ll mul(ll a,ll b,ll m=mod){
	return a*b%m;
}
ll qpow(ll a,ll b,ll m=mod){
	ll ans=1;
	for(;b;a=mul(a,a,m),b>>=1)
		if(b&1)ans=mul(ans,a,m);
	return ans;
}