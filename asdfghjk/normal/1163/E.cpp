#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2000005;
int n,i,j,k,x,a[N],w[N],u[N],xxj[50];
void work(int id,int l,int r)
{
	int mid=(l+r)/2;
	u[mid]=w[id];
	if(l==r)
		return;
	work(id+1,l,mid-1);
	work(id+1,mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	for(x=20;x>0;--x)
	{
		for(i=0;i<x;++i)
			xxj[i]=0;
		for(i=1;i<=n;++i)
			if(a[i]<(1<<x))
			{
				for(j=x-1,k=a[i];j>=0;--j)
					if(k>>j&1)
					{
						if(!xxj[j])
						{
							xxj[j]=k;
							w[j]=a[i];
							break;
						}
						k^=xxj[j];
					}
			}
		for(i=0;i<x;++i)
			if(!xxj[i])
				break;
		if(i>=x)
		{
			printf("%d\n0",x);
			work(0,1,(1<<x)-1);
			for(i=1,j=0;i<(1<<x);++i)
			{
				j^=u[i];
				printf(" %d",j);
			}
			return 0;
		}
	}
	printf("0\n0");
	return 0;
}