#include<bits/stdc++.h>
using namespace std;
const int MAXN=100;
int n,d,ans=0x3f3f3f3f;
int a[MAXN+10];
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			if(a[j]-a[i]<=d)
			{
				ans=min(ans,i-1+n-j);
			}
		}
	}
	printf("%d",ans);
	return 0;
}