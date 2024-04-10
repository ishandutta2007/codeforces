#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN=300005;

int n,m,a[MAXN];

bool check(int mid)
{
	int cur=0;
	for(int i=1;i<=n;i++)
		if(a[i]+mid<m)
		{
			if(cur>a[i]+mid)return 0;
			cur=max(cur,a[i]);
		}
		else if(a[i]+mid-m<cur)
			cur=max(cur,a[i]);
	return 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int L=0,R=m,mid,ans=m;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(check(mid))ans=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}