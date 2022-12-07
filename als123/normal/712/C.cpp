#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int x,y;
int a,b,c;// 
int ans=0;
int main()
{
	scanf("%d%d",&x,&y);
	if (x<y) swap(x,y);
	a=y;b=y;c=y;
	while (a!=x||b!=x||c!=x)
	{
		if (a<=b&&a<=c)//a 
			a=min(x,b+c-1);
		else if (b<=a&&b<=c)
			b=min(x,a+c-1);
		else if (c<=a&&c<=b)
			c=min(x,a+b-1);
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}