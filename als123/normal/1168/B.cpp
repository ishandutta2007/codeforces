#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=300005;
char ss[N];int n;
int main()
{
	scanf("%s",ss+1);n=strlen(ss+1);
	LL ans=0;int r=n+1;
	for (int u=n;u>=1;u--)
	{
		for (int i=1;u+i+i<r;i++)
		{
			if (ss[u]==ss[u+i]&&ss[u+i]==ss[u+i+i])
				r=u+i+i;
		}
		ans=ans+n-r+1;
	}
	printf("%lld\n",ans);
	return 0;
}