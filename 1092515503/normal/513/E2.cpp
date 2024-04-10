#include<bits/stdc++.h>
using namespace std;
int n,m,f[30100][210][3][2],num[30100],sum[30100],s[2][30100][2],res=0x80808080,ass[30100][2];//0- 1+ 20
int main(){
	scanf("%d%d",&n,&m),memset(f,0x80,sizeof(f));
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	for(int i=1;i<=n;i++)f[i][1][0][0]=max(f[i-1][1][0][0],0)-num[i],f[i][1][1][1]=max(f[i-1][1][1][1],0)+num[i];
	for(int i=1;i<=n;i++)f[i][1][2][0]=max(f[i-1][1][2][0],f[i][1][0][0]),f[i][1][2][1]=max(f[i-1][1][2][1],f[i][1][1][1]);
	for(int i=1;i<=n;i++)for(int j=2;j<m;j++){
		f[i][j][0][0]=max({f[i-1][j][0][0],f[i-1][j-1][1][1],f[i-1][j-1][2][1]})-2*num[i];
		f[i][j][1][1]=max({f[i-1][j][1][1],f[i-1][j-1][0][0],f[i-1][j-1][2][0]})+2*num[i];
		f[i][j][2][0]=max({f[i-1][j][2][0],f[i-1][j-1][2][0],f[i-1][j-1][0][0],f[i-1][j][0][0]});
		f[i][j][2][1]=max({f[i-1][j][2][1],f[i-1][j-1][2][1],f[i-1][j-1][1][1],f[i-1][j][1][1]});
	}
	for(int i=n;i>=1;i--)ass[i][0]=max(ass[i+1][0],0)-num[i],ass[i][1]=max(ass[i+1][1],0)+num[i];
	for(int i=m-1;i<n;i++){
		res=max(res,max(f[i][m-1][0][0],f[i][m-1][2][0])+ass[i+1][1]);
		res=max(res,max(f[i][m-1][1][1],f[i][m-1][2][1])+ass[i+1][0]);
	}
	printf("%d\n",res);
	return 0;
}