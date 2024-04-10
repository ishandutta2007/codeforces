#include<bits/stdc++.h>

const int N=105;

int n,p[N],c[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d%d",&p[i],&c[i]);
		int flag=0;
		for (int i=1;i<=n;i++)
			if (p[i]<p[i-1]||c[i]<c[i-1]||p[i]<c[i]||p[i]-p[i-1]<c[i]-c[i-1]) flag=1;
		puts(flag?"NO":"YES");
	}
	return 0;
}