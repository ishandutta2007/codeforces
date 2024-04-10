#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1000005;
int n,a[N],b[N],id1[N],id2[N],i,j,k,x,cirno;
ll s1[N],s2[N];
bool v[N];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		s1[i]=s1[i-1]+a[i];
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",b+i);
		s2[i]=s2[i-1]+b[i];
	}
	if(s1[n]>s2[n])
	{
		cirno=1;
		for(i=1;i<=n;++i)
			swap(s1[i],s2[i]);
	}
	for(i=j=0;i<=n;++i)
	{
		while(s2[j]<s1[i])
			++j;
		k=s2[j]-s1[i];
		if(v[k])
		{
			if(cirno)
			{
				printf("%d\n",j-id2[k]);
				for(x=id2[k]+1;x<=j;++x)
					printf("%d ",x);
				printf("\n%d\n",i-id1[k]);
				for(x=id1[k]+1;x<=i;++x)
					printf("%d ",x);
			}
			else
			{
				printf("%d\n",i-id1[k]);
				for(x=id1[k]+1;x<=i;++x)
					printf("%d ",x);
				printf("\n%d\n",j-id2[k]);
				for(x=id2[k]+1;x<=j;++x)
					printf("%d ",x);
			}
			return 0;
		}
		v[k]=true;
		id1[k]=i,id2[k]=j;
	}
	return 0;
}