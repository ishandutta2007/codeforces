#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,c,a[1005];

int main()
{
	scanf("%d%d%d",&n,&m,&c);
	int mid=c/2,p=0,q=n+1;
	for (int i=1;i<=m;i++)
	{
		int x,ans;
		scanf("%d",&x);
		if (x<=mid)
		{
			if (p<1||a[p]<=x) a[++p]=x,ans=p;
			else
			{
				for (int j=1;j<=p;j++)
					if (a[j]>x) {a[j]=x;ans=j;break;}
			}
		}
		else
		{
			if (q>n||a[q]>=x) a[--q]=x,ans=q;
			else
			{
				for (int j=n;j>=q;j--)
					if (a[j]<x) {a[j]=x;ans=j;break;}
			}
		}
		printf("%d\n",ans);
		fflush(stdout);
		if (p+1==q) break;
	}
	return 0;
}