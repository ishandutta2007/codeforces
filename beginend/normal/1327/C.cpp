#include<bits/stdc++.h>

const int N=205;

int n,m,k,sx[N],sy[N],fx[N],fy[N];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++) scanf("%d%d",&sx[i],&sy[i]);
	for (int i=1;i<=k;i++) scanf("%d%d",&fx[i],&sy[i]);
	printf("%d\n",n+m-2+n*(m-1)+n-1);
	for (int i=1;i<m;i++) putchar('L');
	for (int i=1;i<n;i++) putchar('D');
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<m;j++)
			if (i&1) putchar('R');
			else putchar('L');
		if (i<n) putchar('U');
	}
	return 0;
}