#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
const int MAXN=1005;

int n,m;
double f[3][MAXN][MAXN];//i white j black 0 A 1 B 2 run

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		f[0][i][0]=1;
		f[1][i][0]=0;
		if(i==1)f[2][i][0]=0;
		else f[2][i][1]=1;
		for(int j=1;j<=m;j++)
		{
			f[0][i][j]=f[2][i][j-1]*j/(i+j)+1.0*i/(i+j);
			f[1][i][j]=f[0][i][j-1]*j/(i+j);
			f[2][i][j]=f[1][i][j-1]*j/(i+j)+f[1][i-1][j]*i/(i+j);
		}
	}
	printf("%.12lf\n",f[0][n][m]);
    return 0;
}