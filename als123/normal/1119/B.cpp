#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=300005;
int a[N],b[N];
int n,h;
bool cmp (int x,int y)	{return x>y;}
bool check (int x)
{
	for (int u=1;u<=x;u++)	b[u]=a[u];
	sort(b+1,b+1+x,cmp);
	int sum=0;
	for (int u=1;u<=x;u++)
	{
		if (sum+b[u]>h) return false;
		if (u%2==0) sum=sum+b[u-1];
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&h);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	int l=1,r=n,lalal=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid))	{lalal=mid;l=mid+1;}
		else r=mid-1;
	}
	printf("%d\n",lalal);
	return 0;
}