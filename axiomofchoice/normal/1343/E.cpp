#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf;
#define int ll
int dis1[N],dis2[N],dis3[N],price[N];
int n,m,s1,s2,s3;
vector<int> a[N];
queue<int> q;
void bfs(int s,int dis[]){
	q.push(s);
	fill(dis,dis+n+1,-1);
	dis[s]=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(auto p:a[x])
		if(dis[p]==-1){
			dis[p]=dis[x]+1;
			q.push(p);
		}
	}
}
ll ans;
signed main(){
	for(int T=read();T--;){
		n=read();
		repeat(i,0,n+1)a[i].clear();
		m=read(),s1=read(),s2=read(),s3=read();
		repeat(i,1,m+1)price[i]=read();
		sort(price+1,price+m+1);
		repeat(i,1,m+1)price[i]+=price[i-1];
		repeat(i,0,m){
			int x=read(),y=read();
			a[x].push_back(y);
			a[y].push_back(x);
		}
		bfs(s1,dis1);
		bfs(s2,dis2);
		bfs(s3,dis3);
		ans=INF;
		repeat(i,1,n+1){
			int t2=dis2[i];
			int t1=dis1[i]+dis3[i];
			if(t2+t1<=m)
				ans=min(ans,price[t2]+price[t2+t1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}