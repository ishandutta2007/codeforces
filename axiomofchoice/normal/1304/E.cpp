#include <bits/stdc++.h>
using namespace std; using namespace rel_ops;
/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;*/
#define lll __int128
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
typedef double lf; typedef long double llf; const lf err=1e-11; const lf pi=acos(-1);
typedef pair<int,int> pii;
//typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> rbtree;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}
#define fi first
#define se second
inline ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} inline void read(auto &x){x=read();}
inline lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} inline void readf(auto &x){x=readf();}
inline auto sqr(const auto &x){return x*x;}
ostream &operator<<(ostream &o,const pair<auto,auto> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
mt19937 rnd(time(0));
const int N=500010;
const int mod=(1?1000000007:998244353);
//#define int ll
int n,m,s;
vector<int> a;
vector<int> e[500010];
bool vis[500010];
int pos[500010],dep[500010];
#define mininarr(a,x,y) (a[x]<a[y]?x:y)
struct RMQ{
	#define logN 21
	int f[N][logN],log[N];
	RMQ(){
		log[1]=0;
		repeat(i,2,N)
			log[i]=log[i/2]+1;
	}
	void build(){
		int n=a.size();
		repeat(i,0,n)
			f[i][0]=a[i];
		repeat(k,1,logN)
		repeat(i,0,n-(1<<k)+1)
			f[i][k]=mininarr(dep,f[i][k-1],f[i+(1<<(k-1))][k-1]);
	}
	int query(int l,int r){
		if(l>r)swap(l,r);//!!
		int s=log[r-l+1];
		return mininarr(dep,f[l][s],f[r-(1<<s)+1][s]);
	}
}rmq;
void dfs(int x,int d){
	if(vis[x])return;
	vis[x]=1;
	dep[x]=d;
	a.push_back(x);
	pos[x]=a.size()-1; //
	repeat(i,0,e[x].size()){
		int p=e[x][i];
		if(vis[p])continue;
		dfs(p,d+1);
		a.push_back(x);
	}
}
int lca(int x,int y){
	return rmq.query(pos[x],pos[y]);
}
int length(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	n=read();
	repeat(i,0,n-1){
		int x=read()-1,y=read()-1;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(0,0); rmq.build();
	int q=read();
	while(q--){
		int a=read()-1,b=read()-1;
		int x=read()-1,y=read()-1;
		int qlen=read();
		int len;
		len=length(x,y);
		if(len<=qlen && (len^qlen)%2==0){
			cout<<"YES"<<endl;
			continue;
		}
		len=length(x,a)+1+length(b,y);
		if(len<=qlen && (len^qlen)%2==0){
			cout<<"YES"<<endl;
			continue;
		}
		len=length(x,b)+1+length(a,y);
		if(len<=qlen && (len^qlen)%2==0){
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}