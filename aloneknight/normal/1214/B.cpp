#include<bits/stdc++.h>
using namespace std;
int main()
{
	int b,g,n;scanf("%d%d%d",&b,&g,&n);
	int l1=n-b,r1=n,l2=0,r2=g;
	printf("%d\n",max(0,min(r1,r2)-max(l1,l2)+1));
	return 0;
}