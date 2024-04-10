#include<bits/stdc++.h>
using namespace std;
int n,sum,a[500100];
vector<int>v[1001000];
bool vis[1001000],col[1001000];
void dfs(int x){
	vis[x]=true;
	if(col[x])(sum+=x)%=2*n;
	for(auto y:v[x])if(!vis[y])col[y]=col[x]^1,dfs(y);
}
int main(){
	scanf("%d",&n);
	if(!(n&1)){
		puts("First"),fflush(stdout);
		for(int i=0;i<2*n;i++)printf("%d ",i%n+1);puts(""),fflush(stdout);
	}else{
		puts("Second"),fflush(stdout);
		for(int i=1,x,y;i<=n;i++)v[i].push_back(i+n),v[i+n].push_back(i);
		for(int i=1,x;i<=2*n;i++){
			scanf("%d",&x);
			if(a[x])v[a[x]].push_back(i),v[i].push_back(a[x]);
			else a[x]=i;
		}
		for(int i=1;i<=2*n;i++)if(!vis[i])dfs(i); 
		if(sum){
			for(int i=1;i<=2*n;i++)if(!col[i])printf("%d ",i);
		}else{
			for(int i=1;i<=2*n;i++)if(col[i])printf("%d ",i);
		}
		puts("");fflush(stdout);
	}
	return 0;
}