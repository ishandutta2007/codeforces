#include<bits/stdc++.h>
using namespace std;
int n,m,p,q,mt[1010][1010],dis[1010][1010][41],dd[41][41];
int main(){
	scanf("%d%d%d",&n,&m,&p),memset(dis,0x3f3f3f3f,sizeof(dis)),memset(dd,0x3f3f3f3f,sizeof(dd));
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&mt[i][j]),dis[i][j][mt[i][j]]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=1;k<=p;k++){
		if(i>1)dis[i][j][k]=min(dis[i][j][k],dis[i-1][j][k]+1);
		if(j>1)dis[i][j][k]=min(dis[i][j][k],dis[i][j-1][k]+1);
	}
	for(int i=n;i>=1;i--)for(int j=m;j>=1;j--)for(int k=1;k<=p;k++){
		if(i<n)dis[i][j][k]=min(dis[i][j][k],dis[i+1][j][k]+1);
		if(j<m)dis[i][j][k]=min(dis[i][j][k],dis[i][j+1][k]+1);
	}
	for(int i=1;i<=n;i++)for(int j=m;j>=1;j--)for(int k=1;k<=p;k++){
		if(i>1)dis[i][j][k]=min(dis[i][j][k],dis[i-1][j][k]+1);
		if(j<m)dis[i][j][k]=min(dis[i][j][k],dis[i][j+1][k]+1);
	}
	for(int i=n;i>=1;i--)for(int j=1;j<=m;j++)for(int k=1;k<=p;k++){
		if(i<n)dis[i][j][k]=min(dis[i][j][k],dis[i+1][j][k]+1);
		if(j>1)dis[i][j][k]=min(dis[i][j][k],dis[i][j-1][k]+1);
	}
	for(int i=1;i<=p;i++)dd[i][i]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=1;k<=p;k++)dd[mt[i][j]][k]=dd[k][mt[i][j]]=min(dd[mt[i][j]][k],dis[i][j][k]);
	for(int k=1;k<=p;k++)for(int i=1;i<=p;i++)for(int j=1;j<=p;j++)dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]+1);
//	for(int i=1;i<=p;i++){for(int j=1;j<=p;j++)printf("%d ",dd[i][j]);puts("");}
	scanf("%d",&q);
	for(int i=1,t1,t2,t3,t4;i<=q;i++){
		scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		int res=abs(t3-t1)+abs(t4-t2);
		for(int j=1;j<=p;j++)for(int k=1;k<=p;k++)res=min(res,dis[t1][t2][j]+dd[j][k]+1+dis[t3][t4][k]+(j!=k));
		printf("%d\n",res);
	}
	return 0;
}