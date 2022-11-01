#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,p,l,r;

int main()
{
	scanf("%d%d%d%d",&n,&p,&l,&r);
	int ans;
	if (p<l)
	{
		if (r<n) ans=r-p+2;
		else ans=l-p+1;
	}
	else if (p>r)
	{
		if (l>1) ans=p-l+2;
		else ans=p-r+1;
	}
	else
	{
		if (l>1&&r<n) ans=r-l+2+min(r-p,p-l);
		else if (l>1) ans=p-l+1;
		else if (r<n) ans=r-p+1;
		else ans=0;
	}
	printf("%d",ans);
	return 0;
}