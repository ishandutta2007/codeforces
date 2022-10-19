#include<bits/stdc++.h>
using namespace std;
int n,num[510],f[510][510];
int main(){
	scanf("%d",&n),memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)scanf("%d",&num[i]),f[i][i]=num[i];
	for(int l=2;l<=n;l++)for(int i=1,j=i+l-1;j<=n;i++,j++)for(int k=i;k<j;k++)if(f[i][k]!=-1&&f[k+1][j]!=-1&&f[i][k]==f[k+1][j])f[i][j]=f[i][k]+1;
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)f[i][j]=(f[i][j]==-1?0x3f3f3f3f:1);
	for(int l=2;l<=n;l++)for(int i=1,j=i+l-1;j<=n;i++,j++)for(int k=i;k<j;k++)f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
	printf("%d\n",f[1][n]);
	return 0;
}