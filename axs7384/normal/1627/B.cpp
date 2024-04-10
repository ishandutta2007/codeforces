#include<bits/stdc++.h>
using namespace std;
int t,n,m,cnt;
int a[1000005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		cnt=0;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				a[++cnt]=max(i-1,n-i)+max(j-1,m-j);
		sort(a+1,a+1+cnt);
		for (int i=1;i<=cnt;++i)
			printf("%d%c",a[i],i==cnt?'\n':' ');
	}
	return 0;
}