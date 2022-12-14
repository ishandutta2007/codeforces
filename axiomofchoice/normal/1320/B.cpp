#include <bits/stdc++.h>
using namespace std; //using namespace rel_ops;
#define lll __int128
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
typedef double lf; typedef long double llf; const lf err=1e-11; const lf pi=acos(-1);
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}
#define fi first
#define se second
inline ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
inline lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
//inline auto sqr(const auto &x){return x*x;}
//ostream &operator<<(ostream &o,const pair<auto,auto> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
mt19937 rnd(time(0));
const int N=200010;
const int mod=(1?1000000007:998244353);
//#define int ll
struct node{
	int to,dis;
	bool operator<(node b)const{
		return dis>b.dis;
	}
};
vector<int> a[N];
bool vis[N];
int dis[N],p[N],cnt[N];
int n;
void dijkstra(int s){//s
	repeat(i,0,n+1){
		vis[i]=0;
		dis[i]=2147483647;
	}
	dis[s]=0;
	auto q=priority_queue<node>();
	q.push((node){s,0});
	while(!q.empty()){
		int x=q.top().to; q.pop();
		if(vis[x])continue; vis[x]=1;
		repeat(i,0,a[x].size()){
			int p=a[x][i];
			if(dis[p]>dis[x]+1){
				dis[p]=dis[x]+1; cnt[p]=1;
				q.push((node){p,dis[p]});
			}
			else if(dis[p]==dis[x]+1){
				cnt[p]++;
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	n=read(); int m=read();
	while(m--){
		int x=read(),y=read();
		a[y].push_back(x);
	}
	m=read();
	repeat(i,0,m)p[i]=read();
	reverse(p,p+m);
	dijkstra(p[0]);
	int ans=0,ans2=0;
	repeat(i,0,m-1){
		int dis1=dis[p[i]];
		int dis2=dis[p[i+1]];
		if(dis1+1!=dis2)ans++;
		else if(cnt[p[i+1]]>1)ans2++;
	}
	//orzarr(dis+1,n);
	//orzarr(cnt+1,n);
	cout<<ans<<' '<<ans+ans2<<endl;
	return 0;
}