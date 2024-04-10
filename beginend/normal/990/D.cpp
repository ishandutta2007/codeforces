#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1005;

int n,a,b,t[N][N];

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	if (std::min(a,b)>1) {puts("NO");return 0;}
	if (std::max(a,b)==1&&(n==2||n==3)) {puts("NO");return 0;}
	for (int i=1;i<=n-std::max(a,b);i++) t[i][i+1]=t[i+1][i]=1;
	if (a<b)
	{
		for (int i=1;i<n;i++)
			for (int j=i+1;j<=n;j++)
				t[i][j]=t[j][i]=t[j][i]^1;
	}
	puts("YES");
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%d",t[i][j]);
		puts("");
	}
	return 0;
}