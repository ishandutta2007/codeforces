#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n;
int conleaf[N],d[N];
vector<int> g[N];

void dfs(int x,int f=-1){
	for(int i=0;i<g[x].size();++i)
	if(g[x][i]!=f){
		int y=g[x][i];
		d[y]=d[x]+1;
		dfs(y,x);
	}
}

int main(){
	cin>>n;
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int rt=0;
	for(int i=1;i<=n;++i)
	if(g[i].size()==1){
		conleaf[g[i][0]]++;
	}
	else rt=i;
	d[rt]=1;dfs(rt);
	int ans[2]={0,n-1};
	bool flag[2]={0,0};
	for(int i=1;i<=n;++i)
	if(g[i].size()==1){
		if(!flag[d[i]&1]){
			flag[d[i]&1]=1;
			ans[0]++; 
		}
	}
	else{
		ans[1]-=max(0,conleaf[i]-1);
	}
	if(ans[0]==2)ans[0]=3;
	cout<<ans[0]<<" "<<ans[1]<<endl;
}