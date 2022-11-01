#include<bits/stdc++.h>

const int N=105;

int n,a[N],f[N][N][N][2];
bool vis[N];

int main()
{
	scanf("%d",&n);
	int s1=0,s2=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),vis[a[i]]=1;
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			if (i&1) s1++;
			else s2++;
		}
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;k<=n;k++)
				f[i][j][k][0]=f[i][j][k][1]=n;
	f[0][s1][s2][0]=f[0][s1][s2][1]=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<=s1;j++)
			for (int k=0;k<=s2;k++)
			{
				if (f[i][j][k][0]<n)
				{
					if (a[i+1])
					{
						if (a[i+1]&&(a[i+1]&1)) f[i+1][j][k][1]=std::min(f[i+1][j][k][1],f[i][j][k][0]+1);
						else if (a[i+1]&&!(a[i+1]&1)) f[i+1][j][k][0]=std::min(f[i+1][j][k][0],f[i][j][k][0]);
					}
					else
					{
						if (j) f[i+1][j-1][k][1]=std::min(f[i+1][j-1][k][1],f[i][j][k][0]+1);
						if (k) f[i+1][j][k-1][0]=std::min(f[i+1][j][k-1][0],f[i][j][k][0]);
					}
				}
				if (f[i][j][k][1]<n)
				{
					if (a[i+1])
					{
						if (a[i+1]&&(a[i+1]&1)) f[i+1][j][k][1]=std::min(f[i+1][j][k][1],f[i][j][k][1]);
						else if (a[i+1]&&!(a[i+1]&1)) f[i+1][j][k][0]=std::min(f[i+1][j][k][0],f[i][j][k][1]+1);
					}
					else
					{
						if (j) f[i+1][j-1][k][1]=std::min(f[i+1][j-1][k][1],f[i][j][k][1]);
						if (k) f[i+1][j][k-1][0]=std::min(f[i+1][j][k-1][0],f[i][j][k][1]+1);
					}
				}
			}
	printf("%d\n",std::min(f[n][0][0][0],f[n][0][0][1]));
	return 0;
}