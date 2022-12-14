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
char s[N],t[N];
vector<int> v;
int a[N];
ll ans; 
void merge(int l,int r){
	static int t[N];
	if(r-l<=1)return;
	int mid=l+(r-l)/2;
	merge(l,mid);
	merge(mid,r);
	int p=l,q=mid,s=l;
	while(s<r){
		if(p>=mid || (q<r && a[p]>a[q])){
			t[s++]=a[q++];
			ans+=mid-p;
		}
		else
			t[s++]=a[p++];
	}
	for(int i=l;i<r;++i)a[i]=t[i];
}
void Solve(){
	int n=read();
	scanf("%s",s);
	copy(s,s+n,t);
	repeat(c,'a','z'+1){
		v.clear();
		repeat(i,0,n)
			if(s[i]==c)v<<i;
		repeat(i,0,v.size())
			a[n-v.rbegin()[i]-1]=v[i];
	}
	merge(0,n);
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