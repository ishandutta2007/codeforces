#include<bits/stdc++.h>
using namespace std;
const int N=43;
int sg[N][N][N][N];
char s[N][N];
bool f;
int dfs(int lx,int rx,int ly,int ry){
	int i=sg[lx][rx][ly][ry];
	if(~i)return i;
	bool v[N*5]={};
	int j;
	for(i=lx;i<=rx;++i)for(j=ly;j<=ry;++j)if((i&1)==f){
		if(s[i][j]=='L')v[dfs(lx,i-1,ly,ry)^dfs(i+1,rx,ly,ry)]=1;
		else if(s[i][j]=='R')v[dfs(lx,rx,ly,j-1)^dfs(lx,rx,j+1,ry)]=1;
		else if(s[i][j]=='X')v[dfs(lx,i-1,ly,j-1)^dfs(lx,i-1,j+1,ry)^dfs(i+1,rx,ly,j-1)^dfs(i+1,rx,j+1,ry)]=1;
	}
	for(i=0;;++i)if(!v[i])return sg[lx][rx][ly][ry]=i;
}
int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j){
		scanf(" %c",s[i+j]+i-j+m);
	}
	memset(sg,-1,sizeof sg),f=0;
	i=dfs(2,n+m,1,n+m-1);
	memset(sg,-1,sizeof sg),f=1;
	i^=dfs(2,n+m,1,n+m-1),puts(i?"WIN":"LOSE");
	return 0;
}