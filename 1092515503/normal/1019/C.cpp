#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v[1001000],u;
bool vis[1001000],cho[1001000];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y);
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=cho[i]=true;
		for(auto j:v[i])vis[j]=true;
	}
	for(int i=n;i;i--)if(cho[i])for(auto j:v[i])cho[j]=false;
	for(int i=1;i<=n;i++)if(cho[i])u.push_back(i);
	printf("%d\n",u.size());
	for(auto i:u)printf("%d ",i);
	return 0;
}