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
const int N=6000010; const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod); ll qpow(ll a,ll b,ll m=mod);
#define int ll
struct trie{
	static const int B=30;
	struct node{
		int to[2];
		int &operator[](int n){return to[n];}
	}a[N];
	int t;
	void init(){t=0; add();}
	int add(){a[t]=node(); return t++;}
	void insert(ll s){
		int k=0;
		repeat_back(i,0,B){
			int c=(s>>i)&1; 
			if(!a[k][c])a[k][c]=add();
			k=a[k][c];
		}
	}
	ll query(ll s){
		int k=0; ll ans=0;
		repeat_back(i,0,B){
			int c=(s>>i)&1;
			if(!a[k][c])c^=1,ans^=1ll<<i;
			k=a[k][c];
		}
		return ans;
	}
}t;
int a[N],n; ll ans;
void merge(int l,int r,ll s){
	if(s==0 || l>=r-1)return;
	int m=lower_bound(a+l,a+r,s)-a;
	//cout<<l<<' '<<m<<' '<<r<<' '; orzarr(a,n);
	if(l<m && m<r){
		t.init(); ll mn=INF;
		repeat(i,l,m)t.insert(a[i]);
		repeat(i,m,r)mn=min(mn,t.query(a[i]));
		ans+=mn;
		//orz(mn);
	}
	repeat(i,m,r)a[i]^=s;
	merge(l,m,s>>1); merge(m,r,s>>1);
}
void Solve(){
	n=read();
	repeat(i,0,n)a[i]=read();
	sort(a,a+n);
	merge(0,n,1ll<<31);
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
ll read(){
	ll x; if(scanf("%lld",&x)==-1)exit(0);
	return x;
}
lf readf(){
	lf x; if(scanf("%lf",&x)==-1)exit(0);
	return x;
}
ll mul(ll a,ll b,ll m){
	return a*b%m;
}
ll qpow(ll a,ll b,ll m){
	ll ans=1;
	for(;b;a=mul(a,a,m),b>>=1)
		if(b&1)ans=mul(ans,a,m);
	return ans;
}