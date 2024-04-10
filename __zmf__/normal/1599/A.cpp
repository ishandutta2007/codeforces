#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define int long long
int n;
int a[200008];
int sx[200008];
int jx[200008];
char s[200008];
void dfs1(int l,int r,int n)
{
	if(n==1)
	{
		jx[n]=a[l];
		return ;
	}
	if(sx[n]==sx[n-1])
	{
		jx[n]=a[l];
		dfs1(l+1,r,n-1);
	}else
	{
		jx[n]=a[r];
		dfs1(l,r-1,n-1);
	}
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == 'L') sx[i] = 1;
		else sx[i] = -1;
	}
	sort(a+1,a+n+1);
	if(sx[n]==-1) 
	{
		for(int i=n;i>=1;i=i-2)
		{
			a[i]=-a[i];
		}
	}
	else 
	{
		for(int i=n-1;i>=1;i=i-2)
		{
			a[i]=-a[i];
		}
	}	
	dfs1(1,n,n);
	for(int i=1;i<=n;i++)
	{
		if(jx[i] > 0) printf("%lld L\n", jx[i]);
		else printf("%lld R\n", -jx[i]);
	}
	return 0;
}