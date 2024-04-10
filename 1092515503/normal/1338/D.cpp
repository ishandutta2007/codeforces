#include<bits/stdc++.h>
using namespace std;
int n,f[100100][2],res;
vector<int>v[100100];
void dfs(int x,int fa){
	f[x][1]=1,f[x][0]=v[x].size();
	for(auto y:v[x]){
		if(y==fa)continue;
		dfs(y,x);
		res=max(res,f[x][1]+f[y][0]-1);
		res=max(res,f[x][0]+f[y][1]-1);
		res=max(res,f[x][0]+f[y][0]-2);
		f[x][1]=max(f[x][1],f[y][0]);
		f[x][0]=max(f[x][0],f[y][1]+(int)v[x].size()-1);
		f[x][0]=max(f[x][0],f[y][0]+(int)v[x].size()-2);
	}
	res=max(res,f[x][0]);
	res=max(res,f[x][1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(1,0);
	printf("%d\n",res);
	return 0;
}