#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,m,k;
int p[N],d[N];
vector<int>g1[N],g2[N];
int ans1,ans2;


void bfs(int S,vector<int>g[]){
	queue<int>q;
	d[S]=0;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<g[x].size();++i){
			int y=g[x][i];
			if(y!=S&&!d[y]){
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;++i){
		cin>>x>>y;
		g1[x].push_back(y);
		g2[y].push_back(x);
	}
	cin>>k;
	for(int i=1;i<=k;++i)cin>>p[i];
	bfs(p[k],g2);
	for(int i=1;i<k;++i){
		int x=p[i],y=p[i+1];
		if(d[x]!=d[y]+1){
			ans1++;
			ans2++;
		}
		else{
			bool flag=0;
			for(int j=0;j<g1[x].size();++j){
				int t=g1[x][j];
				if(t!=y&&d[x]==d[t]+1)flag=1;
			}
			if(flag)ans2++;
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
}