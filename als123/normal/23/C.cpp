#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
struct qq
{
	int a,b,id;
}a[N];
int n;
bool cmp (qq x,qq y)	{return x.a<y.a;}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);n=n*2-1;
		for (int u=1;u<=n;u++) 
		{
			scanf("%d%d",&a[u].a,&a[u].b);
			a[u].id=u;
		}
		sort(a+1,a+1+n,cmp);
		printf("YES\n");
		for (int u=1;u<n;u+=2)
		{
			if (a[u].b>a[u+1].b) printf("%d ",a[u].id);
			else printf("%d ",a[u+1].id);
		}
		printf("%d\n",a[n].id);
	}
	return 0;
}