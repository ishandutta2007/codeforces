#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,a[2005];
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=2*n;++i)
		scanf("%d",a+i);
	sort(a+1,a+1+2*n);
	for(i=2;i<=2*n;++i)
		if(a[i]!=a[1])
			break;
	if(i>2*n)
		printf("-1");
	else
	{
		for(i=1;i<=2*n;++i)
			printf("%d ",a[i]);
	}
	return 0;
}