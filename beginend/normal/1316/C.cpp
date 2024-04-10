#include<bits/stdc++.h>

const int N=1000005;

int n,m,p,a[N],b[N];

int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<m;i++) scanf("%d",&b[i]);
	int ans=0;
	for (int i=0;i<n;i++)
		if (a[i]%p!=0)
		{
			ans+=i;
			break;
		}
	for (int i=0;i<m;i++)
		if (b[i]%p!=0)
		{
			ans+=i;
			break;
		}
	printf("%d\n",ans);
	return 0;
}