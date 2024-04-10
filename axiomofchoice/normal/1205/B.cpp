#include <bits/stdc++.h>
using namespace std; //using namespace rel_ops;
#define lll __int128
#define inline __inline __attribute__((always_inline))
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}
#define fi first
#define se second
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
typedef double lf; typedef long double llf; const lf err=1e-11; const lf pi=acos(-1); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;}
typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=100110;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
int dis[N],fa[N],n,ans;
vector<int> a[N];
queue<int> q;
void bfs(int s){
	fill(dis,dis+n,-1); dis[s]=0;
	q.push(s); fa[s]=-1;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(auto p:a[x])
		if(p!=fa[x]){
			if(dis[p]==-1){
				dis[p]=dis[x]+1;
				fa[p]=x;
				q.push(p);
			}
			else{
				//cout<<s<<' '<<x-64<<' '<<p-64<<endl;
				ans=min(ans,dis[x]+dis[p]+1);
			}
		}
	}
}
int cycle(){
	ans=inf;
	repeat(i,0,n)bfs(i);
	return ans;
}
void add(int x,int y){
	a[x].push_back(y);
	a[y].push_back(x);
}
vector<int> bkt[64];
set<pii> eset;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	repeat(i,0,n){
		ll x; cin>>x;
		repeat(j,0,63){
			if((x>>j)&1){
				bkt[j].push_back(i);
				if(bkt[j].size()>=3){cout<<3<<endl,exit(0);}
			}
		}
	}
	repeat(j,0,64)
	if(bkt[j].size()==2)
		eset.insert({bkt[j][0],bkt[j][1]});
	for(auto i:eset)add(i.fi,i.se);
	ans=inf;
	repeat(i,0,64)
	if(bkt[i].size()==2)
		bfs(bkt[i][0]);
	if(ans==inf)ans=-1;
	cout<<ans<<endl;
	return 0;
}