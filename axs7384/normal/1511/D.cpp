#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n,m,cnt;
int main()
{
	scanf("%d%d",&n,&m);
	a[cnt=0]=1;
	for (int i=1;i<m;++i)
	{
		for (int j=i+2;j<=m;++j)
		{
			a[++cnt]=j;
			if (i==1)
				a[++cnt]=j;
			a[++cnt]=i;
		}
		a[++cnt]=i+1;
		if (i==1)
			a[++cnt]=i+1;
	}
	for (int i=m-1;i;--i)
		a[++cnt]=i;
	++cnt;
	// for (int i=0;i<=cnt;++i)
	// 	putchar('a'+a[i]-1);
	for (int i=0;i<n;++i)
		putchar('a'+a[i%cnt]-1);
	return 0;
}