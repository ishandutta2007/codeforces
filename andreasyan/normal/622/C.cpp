#include <iostream>
using namespace std;
const int N=1000006;

int n,m;
int a[N];
int b[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	for(int i=n-1;i>=0;--i)
	{
		if(i==n-1)
		{
			b[i]=-1;
			continue;
		}
		if(a[i]!=a[i+1])
			b[i]=i+1;
		else
			b[i]=b[i+1];
	}
	for(int i=0;i<m;++i)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		--l;
		--r;
		if(x!=a[l])
		{
			printf("%d\n",l+1);
			continue;
		}
		else if(b[l]!=-1 && b[l]<=r)
		{
			printf("%d\n",b[l]+1);
			continue;
		}
		printf("-1\n");
	}
	return 0;
}