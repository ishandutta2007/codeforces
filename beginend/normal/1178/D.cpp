#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int n,d[1005],tim[1005];

bool check(int x)
{
	for (int i=2;i*i<=x;i++)
		if (x%i==0) return 0;
	return 1;
}

void pri(int s1,int s2)
{
	for (int i=1;i<=s1;i++) d[i]=2;
	for (int i=s1+1;i<=n;i++) d[i]=3;
	for (int i=1;i<=n;i++)
	{
		if (!d[i]) continue;
		while (d[i])
		{
			int mx=0;
			for (int j=i+1;j<=n;j++)
				if (d[j]&&tim[j]!=i&&d[j]>d[mx]) mx=j;
			printf("%d %d\n",i,mx);
			d[i]--;d[mx]--;tim[mx]=i;
		}
	}
}

int main()
{
	scanf("%d",&n);
	int p;
	for (int i=n;i;i++) if (check(i)) {p=i;break;}
	int s1=p,s2=0;
	while (s1+s2>n) s1-=3,s2+=2;
	printf("%d\n",p);
	pri(s1,s2);
	return 0;
}