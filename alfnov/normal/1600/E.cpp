#include<bits/stdc++.h>
using namespace std;
int a[200005],zy[200005],yy[200005];
bool solve(int l,int r,int x)
{
	if(a[l]<a[r])
	{
		if(a[r]>x)
		{
			int L=max(l,r-zy[r]+1);
			if((r-L+1)&1)return 1;
		}
		if(a[l]>x)return !solve(l+1,r,a[l]);
	}else
	{
		if(a[l]>x)
		{
			int R=min(r,l+yy[l]-1);
			if((R-l+1)&1)return 1;
		}
		if(a[r]>x)return !solve(l,r-1,a[r]);
	}
	return 0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	zy[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]>a[i])zy[i]=zy[i-1]+1;
		else zy[i]=1;
	}
	yy[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i+1]>a[i])yy[i]=yy[i+1]+1;
		else yy[i]=1;
	}
	if(solve(1,n,-1))printf("Alice\n");
	else printf("Bob\n");
	return 0;
}