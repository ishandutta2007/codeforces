#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=5005;

int n,m,a[N],f[N][N];

int main()
{
	scanf("%d",&m);
	while (m--)
	{
		n++;scanf("%d",&a[n]);
		if (a[n]==a[n-1]) n--;
	}
	int ans=0;
	for (int l=1;l<n;l++)
		for (int i=1;i+l<=n;i++)
		{
			int j=i+l;
			if (a[i]==a[j]) f[i][j]=f[i+1][j-1]+1;
			else f[i][j]=std::max(f[i+1][j],f[i][j-1]);
			ans=std::max(ans,f[i][j]);
		}
	printf("%d\n",n-1-ans);
	return 0;
}