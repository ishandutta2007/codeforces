#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const int M = 1e6+5;

int n,a[N];
vector<int> d[N],point;
vector<int> g[M];
int ans=2e9;

void bfs(int S){
	static int dis[M],vis[M],fa[M];
	static queue<int>q;
	dis[S]=0;
	vis[S]=S;
	fa[S]=0;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<g[x].size();++i){
			int y=g[x][i];
			if(vis[y]!=S){
				dis[y]=dis[x]+1;
				vis[y]=S;
				fa[y]=x;
				q.push(y);
			}
			else if(fa[x]!=y){
				ans=min(ans,dis[x]+dis[y]+1);
			}
		}
	}
} 

int main(){
	cin>>n;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		if(x==(int)sqrt(x)*(int)sqrt(x)){
			cout<<1<<endl;
			return 0;
		}
		a[i]=1;
		for(int j=2;j*j<=x;++j)
		if(x%j==0){
			int c=0;
			while(x%j==0)x/=j,c++;
			if(c&1){
				d[i].push_back(j);
				a[i]*=j;
			}
		}
		if(x>1){
			d[i].push_back(x);
			a[i]*=x;
		}
		if(d[i].size()==1)d[i].push_back(1);
	}
	for(int i=1;i<=n;++i){
		g[d[i][0]].push_back(d[i][1]);
		g[d[i][1]].push_back(d[i][0]);
		point.push_back(d[i][0]);
		point.push_back(d[i][1]);
	}
	sort(point.begin(),point.end());
	point.erase(unique(point.begin(),point.end()),point.end());
	for(int i=0;i<point.size();++i)
	if(point[i]<=1e3){
		bfs(point[i]);
	}
	if(ans<=n)cout<<ans<<endl;
	else cout<<-1<<endl;
}