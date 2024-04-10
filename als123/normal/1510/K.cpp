#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int N=2005;
int n;
int a[N],b[N];
bool check ()
{
	for (int u=2;u<=2*n;u++) if (b[u]<b[u-1]) return false;
	return true; 
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=2*n;u++) scanf("%d",&a[u]);
	for (int u=1;u<=2*n;u++) b[u]=a[u];
	if (check()) {printf("0\n");return 0;}
	int ans=1005;
	for (int u=1;u<=1000;u++)
	{
		if (u&1)
		{
			for (int u=1;u<=2*n;u+=2) swap(b[u],b[u+1]);
			if (check()) {ans=min(ans,u);break;}
		}
		else
		{
			for (int u=1;u<=n;u++) swap(b[u],b[u+n]);
			if (check()) {ans=min(ans,u);break;}
		}
		
	}
	//printf("%d\n",ans);
	for (int u=1;u<=2*n;u++) b[u]=a[u];
	for (int u=1;u<=1000;u++)
	{
		if (u&1)
		{for (int u=1;u<=n;u++) swap(b[u],b[u+n]);
			
			if (check()) {ans=min(ans,u);break;}
		}
		else
		{
			for (int u=1;u<=2*n;u+=2) swap(b[u],b[u+1]);
			if (check()) {ans=min(ans,u);break;}
		}
	}
	if (ans==1005) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}