#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int bin[15],a[3000],n;

int main()
{
	bin[0]=1;
	for (int i=1;i<=12;i++) bin[i]=bin[i-1]*2;
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++)
		{
			int x;scanf("%d",&x);
			if (x<=2048) a[x]++;
		}
		for (int i=0;i<=11;i++) a[bin[i+1]]+=a[bin[i]]/2;
		if (a[2048]) puts("YES");
		else puts("NO");
	}
	return 0;
}