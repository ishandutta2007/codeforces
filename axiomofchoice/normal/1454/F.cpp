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
//#define int ll
#define lb(x) (x&(-x))
struct BIT{
	ll t[N];
	void init(int n){
		fill(t,t+n+1,0);
	}
	void add(int x,ll k){
		for(;x<N;x+=lb(x))
			t[x]+=k;
	}
	ll sum(int x){
		ll ans=0;
		for(;x!=0;x-=lb(x))
			ans+=t[x];
		return ans;
	}
	ll sum(int l,int r){
		return sum(r)-sum(l-1);
	}
}bit;
map<int,vector<int>,greater<int>> a;
void Solve(){
	int n=read(); a.clear(); bit.init(n);
	repeat(i,1,n+1){
		int x=read();
		a[x].push_back(i);
	}
	int l=inf,r=-inf;
	for(auto &k:a){
		vector<int> &v=k.se;
		for(auto i:v){
			bit.add(i,1);
		}
		//orzeach(v);
		if(l==inf)
		if(v.size()>=3){
			l=r=v[1];
			cout<<"YES"<<endl;
			cout<<l-1<<' '<<r-l+1<<' '<<n-r<<endl;
			return;
		}
		if(l!=inf)
		if(v.size()>=3)
		if(v[0]<l && v.back()>r)
		if(bit.sum(l,r)==r-l+1){
			int p=*lower_bound(v.begin(),v.end(),l);
			if(p<=r+1 && p!=v.back()){
				r=max(r,p);
				cout<<"YES"<<endl;
				cout<<l-1<<' '<<r-l+1<<' '<<n-r<<endl;
				return;
			}
			p=*--lower_bound(v.begin(),v.end(),r);
			if(p>=l-1 && p!=v[0]){
				l=min(l,p);
				cout<<"YES"<<endl;
				cout<<l-1<<' '<<r-l+1<<' '<<n-r<<endl;
				return;
			}
		}
		l=min(l,v[0]); r=max(r,v.back());
	}
	cout<<"NO"<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}