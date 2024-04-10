#include<cstdio>
using namespace std;
#define N 1040000
int sz[N],v[N],n,rb;
long long su[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=n;i>=1;i--)
	{
		int s1=1;long long s2=v[i];
		while(rb)
		if(1.0*su[rb]/sz[rb]<1.0*s2/s1)s2+=su[rb],s1+=sz[rb],rb--;
		else break;
		sz[++rb]=s1;su[rb]=s2;
	}
	for(int i=rb;i>=1;i--)
	for(int j=1;j<=sz[i];j++)printf("%.10lf\n",1.0*su[i]/sz[i]);
}