#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

int get(LL n)
{
	int l=1,r=1000000;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if ((LL)mid*mid*mid>=n) r=mid-1;
		else l=mid+1;
	}
	return r+1;
}

bool check(int x,int y)
{
	if (x==1&&y==1) return 1;
	int w=get((LL)x*y);
	if ((LL)w*w*w!=(LL)x*y) return 0;
	if (x%w==0&&y%w==0) return 1;
	else return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (check(x,y)) puts("Yes");
		else puts("No");
	}
	return 0;
}