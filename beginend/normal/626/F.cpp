#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=205;
const int MOD=1000000007;

int n,m,a[N],f[2][N][1005];

void updata(int &x,int y)
{
	x+=y;x-=x>=MOD?MOD:0;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int now=0;
	f[now][0][0]=1;
	for (int i=1;i<=n;i++)
	{
		now^=1;int del=a[i]-a[i-1];
		for (int j=0;j<=(n>>1);j++)
			for (int k=0;k<=m;k++)
			{
				f[now][j][k]=0;
				if (j&&k>=(j-1)*del) updata(f[now][j][k],f[now^1][j-1][k-(j-1)*del]);
				if (k>=(j+1)*del) updata(f[now][j][k],(LL)f[now^1][j+1][k-(j+1)*del]*(j+1)%MOD);
				if (k>=j*del) updata(f[now][j][k],(LL)f[now^1][j][k-j*del]*(j+1)%MOD);
			}
	}
	int ans=0;
	for (int i=0;i<=m;i++) updata(ans,f[now][0][i]);
	printf("%d",ans);
	return 0;
}