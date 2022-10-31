#include<bits/stdc++.h>

const int inf=1e9;

int n,m;

int check(int k,int c)
{
	int w=0;
	for (int i=1;i<=k;i++)
		if (c-i<=k&&i<c-i) w++;
	return w;
}

int main()
{
	scanf("%d%d",&n,&m);
	int sta=n,s=0;
	for (int i=1;i<=n;i++)
		if (s+(i-1)/2>m) {sta=i-1;break;}
		else s+=(i-1)/2;
	int cut=0;
	if (sta==n&&s<m) {puts("-1");return 0;}
	if (s==m)
	{
		for (int i=1;i<=sta;i++) printf("%d ",i);
		for (int i=n;i>sta;i--) printf("%d ",inf-i*(sta+1));
		return 0;
	}
	for (int i=sta+2;i<=sta+n;i++)
		if (s+check(sta,i)==m)
		{
			for (int j=1;j<=sta;j++) printf("%d ",j);
			printf("%d ",i);
			for (int j=n;j>sta+1;j--) printf("%d ",inf-j*(i+1));
			return 0;
		}
	return 0;
}