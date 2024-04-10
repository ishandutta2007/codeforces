#include<bits/stdc++.h>
using namespace std;
int n,m,T;
vector<int>v[100100];
vector<pair<int,int> >u;
void dfs(int x,int fa,int t){
	u.emplace_back(x,t);
	if(fa)v[x].erase(find(v[x].begin(),v[x].end(),fa));
	int tt=t,rem=v[x].size();
	for(auto y:v[x]){
		if(tt==T)u.emplace_back(x,tt=t-rem-1),rem=-1;
		dfs(y,x,++tt);
		u.emplace_back(x,tt);
		if(rem!=-1)rem--;
	}
	if(rem!=-1&&fa)u.emplace_back(x,t-1);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(int i=1;i<=n;i++)T=max(T,(int)v[i].size());
	dfs(1,0,0);
	printf("%d\n",u.size());
	for(auto i:u)printf("%d %d\n",i.first,i.second);
	return 0;
}