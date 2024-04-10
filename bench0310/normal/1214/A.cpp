#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,d,e;
	scanf("%d%d%d",&n,&d,&e);
	int res=n;
	for(int i=0;i*d<=n;i++) res=min(res,(n-i*d)%(5*e));
	printf("%d\n",res);
	return 0;
}