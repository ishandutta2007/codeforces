#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAX=1e9;
const int N=100005;
int n;
int a[N];
char ss[N];
int mx=1e9,mn=-1e9;
int l=MAX,L=-MAX;
int r=MAX,R=-MAX;
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	scanf("%s",ss+1);
	for (int u=5;u<=n;u++)
	{
		if (ss[u]=='1')//1 
		{
			if (ss[u]==ss[u-1])
			{
				int p=MAX;
				for (int i=0;i<=4;i++)
					p=min(p,a[u-i]);
				R=max(r,p);
			}
			else
			{
				int p=-MAX;
				for (int i=0;i<=4;i++)
					p=max(p,a[u-i]);
				L=max(L,p+1);
			}
		}
		else
		{
			if (ss[u]==ss[u-1])
			{
				int p=-MAX;
				for (int i=0;i<=4;i++)
					p=max(p,a[u-i]);
				l=min(l,p);
			}
			else
			{
				int p=MAX;
				for (int i=0;i<=4;i++)
					p=min(p,a[u-i]);
				r=min(r,p-1);
			}
		}
	}
	printf("%d %d\n",L,r);
	return 0;
}