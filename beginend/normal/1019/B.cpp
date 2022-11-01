#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

int n;

int query(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}

bool check(int a,int b)
{
	return (LL)a*b>0;
}

int main()
{
	scanf("%d",&n);
	int x=query(1),y=query(1+n/2);
	if (x==y) {printf("! %d\n",1);return 0;}
	x=x-y;y=-x;
	int l=1+1,r=n/2;
	while (l<=r)
	{
		int mid=(l+r)/2;
		int w=query(mid)-query(mid+n/2);
		if (!w) {printf("! %d\n",mid);return 0;}
		else if (check(w,x)) l=mid+1,x=w;
		else r=mid-1,y=w;
	}
	printf("! %d\n",-1);
	return 0;
}