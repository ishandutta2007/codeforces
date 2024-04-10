#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N];
char ss[N];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	scanf("%s",ss+1);
	int l=1;
	int mn=n+1,mx=0;
	int mxx=0;
	for (int u=1;u<=n;u++)
	{
		mn=min(mn,a[u]);
		mx=max(mx,a[u]);
		if (ss[u]=='0')//0lu 
		{
			if (mn<mxx)
			{
				printf("NO\n");
				return 0;
			}
			mxx=mx;
			mn=n+1;mx=0;
		}
	}
	if (mn<mxx)	printf("NO\n");
	else printf("YES\n");
	return 0;
}