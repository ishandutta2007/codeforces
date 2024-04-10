#include<bits/stdc++.h>
using namespace std;
int t,n,cnt1,cnt2,a[100005],b[100005];
int x,y;
double ans;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=2*n;++i)
		{
			scanf("%d%d",&x,&y);
			if (x==0)
				a[++cnt1]=abs(y);
			else
				b[++cnt2]=abs(x);
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for (int i=1;i<=n;++i)
			ans+=sqrt((double)a[i]*a[i]+(double)b[i]*b[i]);
		printf("%.10lf\n",ans);
		cnt1=cnt2=0;
		ans=0;
	}
}