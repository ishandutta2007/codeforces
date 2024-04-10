#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN=1005;
int n;
double m,a[MAXN<<1|1];

int main()
{
	scanf("%d%lf",&n,&m);
	scanf("%lf%lf",&a[1],&a[n<<1]);
	for(int i=1;i<n;i++)
		scanf("%lf%lf",&a[i<<1|1],&a[i<<1]);
	n<<=1;
	double ans=0;
	for(int i=n;i>0;i--)
	{
		if(a[i]<1+1e-8)return 0*printf("-1\n");
		ans=(ans*a[i]+m)/(a[i]-1);
	}
	printf("%.10lf\n",ans);
	return 0;
}