#include<cstdio>
#include<cstring>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,a[139][139],t,now,flag[139][139],d[139][139];
int xp[4]={1,0,-1,0};
int yp[4]={0,1,0,-1};
inline void dfs(int x,int y,int w){
	d[x][y]=w;flag[x][y]=1;
	for(int i=0;i<=3;i++){
		int nowx=xp[i]+x,nowy=yp[i]+y;
	    if(nowx<1||nowx>n||nowy<1||nowy>m||flag[nowx][nowy]) continue;
		if(a[nowx][nowy]==a[x][y]) dfs(nowx,nowy,w^1);
		else if(a[nowx][nowy]==a[x][y]+1||a[nowx][nowy]+1==a[x][y]) dfs(nowx,nowy,w);
	}
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(d,0,sizeof(d));memset(flag,0,sizeof(flag));
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(!flag[i][j]) dfs(i,j,0);
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) printf("%d ",a[i][j]+d[i][j]);
			printf("\n");
		}
	}
}