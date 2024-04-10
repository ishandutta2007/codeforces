#include<bits/stdc++.h>
using namespace std;
int n,m,f[1001][2001][4];
const int M=998244353;
int main()
{
	scanf("%d%d",&n,&m);
	f[1][1][3]=1,f[1][2][2]=1,f[1][2][1]=1,f[1][1][0]=1;
	for(int i=2;i<=n;i++)for(int j=1;j<=m;j++){
		f[i][j][0]=(((f[i-1][j][0]+f[i-1][j][1])%M+f[i-1][j][2])%M+f[i-1][j-1][3])%M;
		f[i][j][3]=(((f[i-1][j][0]+f[i-1][j][1])%M+f[i-1][j][2])%M+f[i-1][j-1][0])%M;
		f[i][j][1]=(((f[i-1][j-1][0]+f[i-1][j-1][3])%M+f[i-1][j][1])%M+f[i-1][j-2][2])%M;
		f[i][j][2]=(((f[i-1][j-1][0]+f[i-1][j-1][3])%M+f[i-1][j-2][1])%M+f[i-1][j][2])%M;
	}
	printf("%d",(((f[n][m][0]+f[n][m][1])%M+f[n][m][2])%M+f[n][m][3])%M);
	return 0;
}