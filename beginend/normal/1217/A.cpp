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
		int t=(x+z-y+1)/2;
		t=std::min(t,z+1);
		t=std::max(t,0);
		printf("%d\n",t);
	}
	return 0;
}