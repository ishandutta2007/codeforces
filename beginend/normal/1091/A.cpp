#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int main()
{
	int y,b,r;
	scanf("%d%d%d",&y,&b,&r);
	int t=std::min(y,std::min(b-1,r-2));
	printf("%d\n",t*3+3);
	return 0;
}