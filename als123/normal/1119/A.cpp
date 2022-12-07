#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=300005;
int c[N];
int n;
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&c[u]);
	int mn;
	for (int u=2;u<=n;u++)	if (c[u]!=c[1])	{mn=u;break;}
	int ans=0;
	for (int u=2;u<=n;u++)
	{
		if (c[u]!=c[1]) ans=max(ans,u-1);
		else ans=max(ans,u-mn);
	}
	for (int u=n;u>=1;u--) if (c[u]!=c[n]) {mn=u;break;}
	for (int u=1;u<n;u++) 
	{
		if (c[u]!=c[n]) ans=max(ans,n-u);
		else ans=max(ans,mn-u);
	}
	printf("%d\n",ans);
	return 0;
}