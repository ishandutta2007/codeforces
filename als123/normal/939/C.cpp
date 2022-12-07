#include<cstdio>
#include<algorithm>
typedef long long LL;
const int N=100005;
int n;
int a[N];
int S,F;
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	scanf("%d%d",&S,&F);
	int now=0;
	for (int u=S;u<F;u++) now=now+a[u];
	int l=S,r=F-1;
	int ans=now,ans1=1;
	for (int u=2;u<=n;u++)
	{
		now=now-a[r];
		r--;r=r+n;r%=n;if (r==0) r=n;
		l--;l=l+n;l%=n;if (l==0) l=n;
		now=now+a[l];
		if (now>ans)
		{
			ans=now;
			ans1=u;
		}
	}
	printf("%d\n",ans1);
	return 0;
}