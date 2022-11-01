#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=705;

int n,a[N];
bool con[N][N],f[N][N][2];

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			con[j][i]=con[i][j]=(gcd(a[i],a[j])>1);
	for (int i=1;i<=n;i++)
	{
		if (con[i][i-1]) f[i][i][0]=1;
		if (con[i][i+1]) f[i][i][1]=1;
	}
	for (int l=1;l<n;l++)
		for (int i=1;i+l<=n;i++)
		{
			int j=i+l;
			for (int k=i;k<=j;k++)
				if (con[k][i-1]&&(i==k||f[i][k-1][1])&&(j==k||f[k+1][j][0])) {f[i][j][0]=1;break;}
			for (int k=i;k<=j;k++)
				if (con[k][j+1]&&(i==k||f[i][k-1][1])&&(j==k||f[k+1][j][0])) {f[i][j][1]=1;break;}
		}
	for (int i=1;i<=n;i++)
		if ((i==1||f[1][i-1][1])&&(i==n||f[i+1][n][0])) {puts("Yes");return 0;}
	puts("No");
	return 0;
}