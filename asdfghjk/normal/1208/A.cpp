#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t,a,b,n;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&n);
		if(n%3==0)
			printf("%d\n",a);
		else if(n%3==1)
			printf("%d\n",b);
		else
			printf("%d\n",a^b);
	}
	return 0;
}