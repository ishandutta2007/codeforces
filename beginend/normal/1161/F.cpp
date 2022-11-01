#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=55;

int n,gi[N],bo[N],mat[N],ord[N][N],a[N][N],now;

bool cmp(int x,int y)
{
	return a[now][x]>a[now][y];
}

void get_match()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) ord[i][j]=j;
		now=i;
		std::sort(ord[i]+1,ord[i]+n+1,cmp);
	}
	for (int i=1;i<=n;i++) gi[i]=bo[i]=mat[i]=0;
	bool flag=0;
	while (!flag)
	{
		flag=1;
		for (int i=1;i<=n;i++) if (!gi[i])
		{
			flag=0;
			mat[i]++;
			int y=ord[i][mat[i]];
			if (!bo[y]) bo[y]=i,gi[i]=y;
			else
			{
				int x=bo[y];
				if (a[i][y]<a[x][y]) gi[x]=0,bo[y]=i,gi[i]=y;
			}
		}
	}
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		puts("B");fflush(stdout);
		char str[2];scanf("%s",str);
		if (str[0]=='D')
		{
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					a[i][j]=-a[i][j];
		}
		int pos;scanf("%d",&pos);
		if (pos<=n)
		{
			for (int i=1;i<n;i++)
				for (int j=i+1;j<=n;j++)
					std::swap(a[i][j],a[j][i]);
		}
		get_match();
		bool swit=(pos<=n);
		while (pos>0)
		{
			pos-=pos>n?n:0;
			printf("%d\n",bo[pos]+(swit?n:0));fflush(stdout);
			scanf("%d",&pos);
		}
		if (pos==-2) return 0;
	}
	return 0;
}