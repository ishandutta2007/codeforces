#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=500005;
int n;
int a[N];
bool check (int x)//x 
{
	//printf("%d\n",x);
	int now=x+1;
	for (int u=1;u<=x;u++)
	{
		while (now<=n&&a[now]<2*a[u])  now++;
		if (now>=n+1) return false;
		now++;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	sort(a+1,a+1+n);
	int l=0,r=n;// 
	int ans;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) {ans=mid;l=mid+1;}
		else r=mid-1;
	}
	printf("%d\n",n-ans);
	return 0;
}