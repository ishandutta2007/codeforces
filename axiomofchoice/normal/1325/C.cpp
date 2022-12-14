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
const int N=200010;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
ll t,n;
vector<int> a[N];
int ans[N];
map<pii,int> Map;
vector<pii> eset;
int cnt;
void output(){
	for(auto i:eset){
		if(Map.count(i))
			cout<<Map[i]<<endl;
		else if(Map.count({i.se,i.fi}))
			cout<<Map[{i.se,i.fi}]<<endl;
		else
			cout<<cnt++<<endl;
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n=read();
	mst(ans,-1);
	repeat(i,0,n-1){
		int x=read()-1,y=read()-1;
		a[x].push_back(y);
		a[y].push_back(x);
		eset.push_back({x,y});
	}
	repeat(i,0,n)
	if(a[i].size()>3){
		repeat(j,0,4)
			Map[{i,a[i][j]}]=cnt++;
		output();
		exit(0);
	}
	repeat(i,0,n)
	if(a[i].size()==3){
		int s=-1;
		repeat(j,0,3)
		if(a[a[i][j]].size()>1)
			s=a[i][j];
		repeat(j,0,3)
		if(a[i][j]!=s)
			Map[{i,a[i][j]}]=cnt++;
		if(s!=-1){
			Map[{i,s}]=cnt++;
			if(a[s][0]!=i){
				Map[{s,a[s][0]}]=cnt++;
			}
			else{
				Map[{s,a[s][1]}]=cnt++;
			}
		}
		output();
		exit(0);
	}
	output();
	return 0;
}