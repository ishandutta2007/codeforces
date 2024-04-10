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
int ans[N];
int query(int x,int y){
	cout<<"? "<<x<<' '<<y<<endl; cout.flush();
	int a; cin>>a;
	cout<<"? "<<y<<' '<<x<<endl; cout.flush();
	int b; cin>>b;
	if(a>b){ans[x]=a; return y;}
	else {ans[y]=b; return x;}
} 
void Solve(){
	int n; cin>>n;
	int p=1;
	repeat(i,2,n+1)
		p=query(p,i);
	cout<<"! ";
	repeat(i,1,n+1){
		if(ans[i]==0)ans[i]=n;
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
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