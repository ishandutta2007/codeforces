#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005;
int T;
int n;
struct qq{int l,r,id;}a[N];
bool cmp (qq x,qq y)	{return x.l<y.l;}
int bel[N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int u=1;u<=n;u++)	
		{
			scanf("%d%d",&a[u].l,&a[u].r);
			a[u].id=u;
		}
		sort(a+1,a+1+n,cmp);
		int mx=a[1].r;bel[a[1].id]=1;
		bool tf=false;
		for (int u=2;u<=n;u++)
		{
			if (a[u].l>mx)
			{
				tf=true;
				for (int i=u;i<=n;i++) bel[a[i].id]=2;
				break;
			}
			bel[a[u].id]=1;
			mx=max(mx,a[u].r);
		}
		if (tf==false) printf("-1\n");
		else
		{
			for (int u=1;u<=n;u++) printf("%d ",bel[u]);
			printf("\n");
		}
	}
	return 0;
}