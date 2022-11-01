#include<bits/stdc++.h>

const int N=100005;

int n,a[N],b[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)
			scanf("%d",&b[i]),a[i]-=b[i];
		for (int i=1;i<=n;i++)
			if (a[i]<0)
			{
				int k=a[i];
				while (i<=n&&a[i]==k) a[i]=0,i++;
				break;
			}
		bool flag=0;
		for (int i=1;i<=n;i++)
			if (a[i]!=0) {flag=1;break;}
		puts(flag?"NO":"YES");
	}
	return 0;
}