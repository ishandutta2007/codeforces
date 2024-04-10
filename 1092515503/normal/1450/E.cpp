#include<bits/stdc++.h>
using namespace std;
int n,m,dis[210][210],X[2010],Y[2010];
int main(){
	scanf("%d%d",&n,&m),memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(z==1)dis[x][y]=1,dis[y][x]=-1;
		else dis[x][y]=dis[y][x]=1;
		X[i]=x,Y[i]=y;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int res=-1,mxp=0;
	for(int i=1;i<=n;i++){
		if(dis[i][i]<0){puts("NO");return 0;}
		int mn=0x3f3f3f3f,mx=-0x3f3f3f3f;
		for(int j=1;j<=n;j++)mn=min(mn,dis[i][j]),mx=max(mx,dis[i][j]);
		for(int j=1;j<=m;j++)if(dis[i][X[j]]==dis[i][Y[j]])mx=mn-1;
		if(res<mx-mn)res=mx-mn,mxp=i;
	}
	if(res==-1){puts("NO");return 0;}
	puts("YES");
	printf("%d\n",res);
	for(int i=1;i<=n;i++)printf("%d ",dis[mxp][i]+res);puts(""); 
	return 0;
}