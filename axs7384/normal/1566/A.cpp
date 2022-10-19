#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		n=n/2+1;
		printf("%d\n",m/n);
	} 
	return 0;
}