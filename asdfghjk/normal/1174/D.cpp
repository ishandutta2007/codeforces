#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,x,i,a[1500000],len;
bool v[1500000];
int main()
{
	//freopen("d.in","r",stdin);
	//freopen("d.out","w",stdout);
	scanf("%d%d",&n,&x);
	v[0]=true;
	if(x<(1<<n))
		v[x]=true;
	for(i=1;i<(1<<n);++i)
		if(!v[i])
		{
			if((i^x)>i)
				v[i^x]=true;
			a[++len]=i;
		}
	printf("%d\n",len);
	for(i=1;i<=len;++i)
		printf("%d ",a[i]^a[i-1]);
	return 0;
}