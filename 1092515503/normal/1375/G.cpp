#include<bits/stdc++.h>
using namespace std;
int n,c[2];
vector<int>v[200100];
void dfs(int x,int fa,bool tp){c[tp]++;for(auto y:v[x])if(y!=fa)dfs(y,x,!tp);}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(1,0,0);
	printf("%d\n",min(c[0],c[1])-1);
	return 0;
}