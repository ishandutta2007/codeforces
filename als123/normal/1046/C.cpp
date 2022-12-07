#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=200005;
int n,m;
int a[N];
int b[N];
int now;
bool check (int x)// 
{
	bool tf=true;
	int xx=n+1;
	for (int u=x+1;u<=n;u++)
	{
		//printf("%d %d %d\n",a[u],b[xx],a[u]+b[xx]);
		if (a[u]+b[xx]>now)
			tf=false;
		xx--;
	}
	return tf;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	for (int u=1;u<=n;u++) scanf("%d",&b[u]);
	now=a[m]+b[1];
	for (int u=m;u<n;u++) a[u]=a[u+1];
	n--;
	int lalal=0;
	int l=0,r=n;// 
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) {lalal=mid;r=mid-1;}
		else l=mid+1;
	}
	printf("%d\n",lalal+1);
	return 0;
}