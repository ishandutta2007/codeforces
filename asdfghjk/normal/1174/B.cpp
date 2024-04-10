#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,a[100005],c1,c2;
int main()
{
	//freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(a[i]%2==0)
			++c1;
		else
			++c2;
	}
	if(!(c1==0||c2==0))
		sort(a+1,a+1+n);
	for(i=1;i<=n;++i)
		printf("%d ",a[i]);
	return 0;
}