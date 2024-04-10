#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],x,y,i;
double ans;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<(1<<n);++i)
	{
		scanf("%d",&a[i]);
		ans+=1.0*a[i]/(1<<n);
	}
	printf("%.12lf\n",ans);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		ans-=1.0*a[x]/(1<<n);
		a[x]=y;
		ans+=1.0*a[x]/(1<<n);
		printf("%.12lf\n",ans);
	}
}