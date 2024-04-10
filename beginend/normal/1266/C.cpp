#include<bits/stdc++.h>

int n,m;

int gcd(int x,int y)
{
	return !y?x:gcd(y,x%y);
}

int main()
{
	scanf("%d%d",&n,&m);
	if (n==1&&m==1) {puts("0");return 0;}
	if (m==1)
	{
		for (int i=1;i<=n;i++) printf("%d\n",i+1);
		return 0;
	} 
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) printf("%d ",i*(j+n)/gcd(i,j+n));
		puts("");
	}
	return 0;
}