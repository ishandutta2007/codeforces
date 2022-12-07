#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=200005;
int n,m,k;
int a[N];
int q[N];// 
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if (n==1&&k<=1)
	{
		printf("1\n");
		return 0;
	}
	for (int u=1;u<=n;u++)
		scanf("%d",&a[u]);
	sort(a+1,a+1+n);
	int r=1;
	int ans=0;
	int L=1,R=1;
	q[1]=1;
	while (r<n)
	{
		if (L>R) {L=1;R=1;q[1]=++r;}
		while (r+1<=n&&a[r+1]-a[q[L]]+1<=m)	q[++R]=++r;
		while ((R-L+1)>=k)	{R--;ans++;}
		L++;
	}
	printf("%d\n",ans);
	return 0;
}