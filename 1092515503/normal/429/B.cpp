#include<bits/stdc++.h>
using namespace std;
int g[1011][1011],f1[1011][1011],f2[1011][1011],f3[1011][1011],f4[1011][1011],n,m,mx;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&g[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f1[i][j]=max(f1[i-1][j],f1[i][j-1])+g[i][j];
	for(int i=1;i<=n;i++)for(int j=m;j;j--)f2[i][j]=max(f2[i-1][j],f2[i][j+1])+g[i][j];
	for(int i=n;i;i--)for(int j=1;j<=m;j++)f3[i][j]=max(f3[i+1][j],f3[i][j-1])+g[i][j];
	for(int i=n;i;i--)for(int j=m;j;j--)f4[i][j]=max(f4[i+1][j],f4[i][j+1])+g[i][j];
	for(int i=2;i<n;i++)for(int j=2;j<m;j++)mx=max(mx,max(f1[i][j-1]+f2[i-1][j]+f3[i+1][j]+f4[i][j+1],f1[i-1][j]+f2[i][j+1]+f3[i][j-1]+f4[i+1][j]));
	printf("%d\n",mx);
	return 0;
}