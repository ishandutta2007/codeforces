#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		int l=0,r=1e8;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (x>=mid&&y>=mid&&x+y+z>=mid*3) l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",l-1);
	}
	return 0;
}