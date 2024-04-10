#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if((n&3)==2 || (n&3)==3)return 0&puts("NO");
	puts("YES");
	for(int i=(n>>2);i;--i)
	{
		for(int j=1;j<i;++j)for(int a=4*(j-1)+1;a<=4*(j-1)+3;a+=2)for(int b=4*(i-1)+1;b<=4*(i-1)+3;b+=2)printf("%d %d\n%d %d\n%d %d\n%d %d\n",a,b,a+1,b+1,a,b+1,a+1,b);
		if(!(n&3))printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",4*(i-1)+1,4*(i-1)+2,4*(i-1)+3,4*(i-1)+4,4*(i-1)+1,4*(i-1)+3,4*(i-1)+2,4*(i-1)+4,4*(i-1)+1,4*(i-1)+4,4*(i-1)+2,4*(i-1)+3);
		else
		{
			for(int a=4*(i-1)+1;a<=4*(i-1)+3;a+=2)printf("%d %d\n%d %d\n%d %d\n",a,n,a,a+1,a+1,n);
			printf("%d %d\n%d %d\n%d %d\n%d %d\n",4*(i-1)+1,4*(i-1)+4,4*(i-1)+2,4*(i-1)+3,4*(i-1)+1,4*(i-1)+3,4*(i-1)+2,4*(i-1)+4);
		}
	}
	return 0;
}