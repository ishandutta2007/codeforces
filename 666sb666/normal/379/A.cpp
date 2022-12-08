#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c=0,ans=0;
	scanf("%d%d",&a,&b);
	while(a)
	{
		ans+=a;
		c+=a;
		a=c/b,c%=b;
	}
	printf("%d\n",ans);
	return 0;
}