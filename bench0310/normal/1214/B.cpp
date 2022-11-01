#include <bits/stdc++.h>

using namespace std;

int main()
{
	int b,g,n;
	scanf("%d%d%d",&b,&g,&n);
	int res=0;
	for(int i=0;i<=n;i++) res+=(i<=b&&(n-i)<=g);
	printf("%d\n",res);
	return 0;
}