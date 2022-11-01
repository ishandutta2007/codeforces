#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,mx[15],a[N],col[N];
char s[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		memset(mx,0,sizeof(mx));
		for (int i=1;i<=n;i++)
		{
			a[i]=s[i]-'0';
			mx[a[i]]=i;
			col[i]=0;
		}
		int ls=0,pos=0,mn=10;
		for (int i=0;i<=9;i++)
		{
			for (int j=pos+1;j<=mx[i];j++)
				if (a[j]==i&&a[j]<=mn) col[j]=1,ls=i,pos=j;
				else mn=std::min(mn,a[j]);
		}
		int w=0;bool flag=0;
		for (int i=1;i<=n;i++)
			if (!col[i])
			{
				col[i]=2;
				if (a[i]<ls) flag=1;
				else ls=a[i];
			}
		if (flag) puts("-");
		else
		{
			for (int i=1;i<=n;i++) printf("%d",col[i]);
			puts("");
		}
	}
	return 0;
}