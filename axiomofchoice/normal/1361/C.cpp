#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
#define fi first
#define se second
#ifndef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=1000010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<ll,ll> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
int T,n,p;
struct DSU{
	int a[N],sz[N];
	void init(int n){
		iota(a,a+n+1,0);
		fill(sz,sz+n+1,1);
	}
	int fa(int x){
		return a[x]==x?x:a[x]=fa(a[x]);
	}
	bool query(int x,int y){ //
		return fa(x)==fa(y);
	}
	void join(int x,int y){ //
		x=fa(x),y=fa(y);
		if(x==y)return;
		if(sz[x]>sz[y])swap(x,y);
		a[x]=y;
		sz[y]+=sz[x];
	}
}d,d2;
struct node{int x,p;}a[N];
string s;

namespace getans{
vector<int> a[N];
typedef pair<int,int> pii;
vector<pii> ans;
bool vis[N];
void dfs(int i){
	while(!a[i].empty()){
		int x=a[i].back(),y=x^1,p=x/2;
		a[i].pop_back();
		if(vis[p])continue; vis[p]=1; 
		dfs(d.fa(y));
		ans.push_back({x+1,y+1});
	}
}
void getans(){
	repeat(i,0,n){
		int x=i*2,y=i*2+1;
		a[d.fa(x)].push_back(x);
		a[d.fa(y)].push_back(y);
	}
	dfs(d.fa(0));
	repeat_back(i,0,ans.size())cout<<ans[i].fi<<' '<<ans[i].se<<' ';
}
}

signed main(){
	cin>>n;
	repeat(i,0,n*2){
		cin>>a[i].x; s=bitset<20>(a[i].x).to_string();
		reverse(s.begin(),s.end());
		a[i].x=bitset<20>(s).to_ulong();
		a[i].p=i;
	}
	d.init(n*2);
	d2.init(n*2);
	sort(a,a+n*2,[](node a,node b){return a.x<b.x;});
	repeat(i,0,n)d2.join(i*2,i*2+1);
	
//	repeat(i,0,n*2){
//		cout<<bitset<20>(a[i].x)<<endl;
//	}
	repeat(k,0,21){
		repeat(i,0,n*2-1){
			if((a[i].x>>k)==(a[i+1].x>>k))
				d.join(a[i].p,a[i+1].p),
				d2.join(a[i].p,a[i+1].p);
		}
		int f=true;
		if(d2.sz[d2.fa(0)]!=n*2)f=false;
		repeat(i,0,n*2)
			if(d.sz[d.fa(i)]%2==1)f=false;
		if(f){
			cout<<20-k<<endl;
			getans::getans();
			break;
		}
	}
	return 0;
}