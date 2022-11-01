#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int MOD=1000000007;

int n,bin[35],f[35][35][2];

void updata(int &x,int y)
{
	x+=y;x-=x>=MOD?MOD:0;
}

int main()
{
	scanf("%d",&n);
	bin[0]=1;
	for (int i=1;i<=30;i++) bin[i]=bin[i-1]*2;
	for (int i=30;i>=0;i--)
		if (n&bin[i]) {f[i][1][1]=f[i][0][0]=1;break;}
	for (int i=30;i>=1;i--)
		for (int j=0;j<=30;j++)
		{
			if (f[i][j][0])
			{
				updata(f[i-1][j+1][0],f[i][j][0]);
				updata(f[i-1][j][0],(LL)f[i][j][0]*bin[j]%MOD);
			}
			if (f[i][j][1])
			{
				if (n&bin[i-1])
				{
					updata(f[i-1][j+1][1],f[i][j][1]);
					updata(f[i-1][j][0],(LL)f[i][j][1]*bin[j-1]%MOD);
					updata(f[i-1][j][1],(LL)f[i][j][1]*bin[j-1]%MOD);
				}
				else updata(f[i-1][j][1],(LL)f[i][j][1]*bin[j-1]%MOD);
			}
		}
	int ans=0;
	if (!n) ans++;
	for (int i=0;i<=30;i++) updata(ans,f[0][i][0]),updata(ans,f[0][i][1]);
	printf("%d",ans);
	return 0;
}