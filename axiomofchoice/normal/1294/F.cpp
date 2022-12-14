#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll; const int inf=2e9;
typedef double lf; const lf err=1e-7;
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define Clear(a) (a=decltype(a)())
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
ll read(){ll n; scanf("%lld",&n); return n;}
const int N=200010;
const int mod=998244353;
//#define int ll
int n,maxd,maxp;
vector<int> a[N];
bool vis[N];
int last[N],dis[N];
void dfs(int x,int d){
	vis[x]=1;
	if(maxd<d){
		maxp=x;
		maxd=d;
	}
	for(auto p:a[x])
	if(!vis[p])
		dfs(p,d+1),last[p]=x;
}
signed main(){
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	n=read();
	repeat(i,0,n-1){
		int u=read()-1,v=read()-1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	maxd=-1;
	dfs(0,0);
	int v1=maxp;
	fill(vis,vis+n+1,0);
	maxd=-1;
	dfs(v1,0); int ans=maxd;
	int v2=maxp; last[v1]=-1;
	auto q=queue<int>();
	for(int i=v2;i!=-1;i=last[i])
		q.push(i),dis[i]=1;
	fill(vis,vis+n+1,0);
	maxd=1;
	maxp=last[v2];
	while(!q.empty()){
		int x=q.front(); q.pop();
		if(dis[x]>maxd){
			maxd=dis[x];
			maxp=x;
		}
		for(auto p:a[x])
		if(dis[p]==0){
			dis[p]=dis[x]+1;
			q.push(p);
		}
	}
	ans+=maxd;
	cout<<ans-1<<endl;
	cout<<v1+1<<' '<<v2+1<<' '<<maxp+1<<endl;
	return 0;
}