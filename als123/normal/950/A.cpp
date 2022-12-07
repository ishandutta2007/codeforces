#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int l,r,a;
int main()
{
	scanf("%d%d%d",&l,&r,&a);
	if (l>r) swap(l,r);
	int lalal=r-l;
	if (a<lalal)
		printf("%d\n",(l+a)*2);
	else
	{
		a=a-lalal;
		l+=lalal;
		if (a&1) a--;
		printf("%d\n",l+r+a);
	}
	return 0;
}