#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,a,b,c;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	int ans=0,now=1;
	for (int i=1;i<n;i++)
	{
		if (now==1)
		{
			if (a<b) now=2,ans+=a;
			else now=3,ans+=b;
		}
		else if (now==2)
		{
			if (a<c) now=1,ans+=a;
			else now=3,ans+=c;
		}
		else
		{
			if (b<c) now=1,ans+=b;
			else now=2,ans+=c;
		}
	}
	cout<<ans;
	return 0;
}