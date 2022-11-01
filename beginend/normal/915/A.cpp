#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,k;

int main() 
{
	scanf("%d%d",&n,&k);
	int ans=k;
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		if (k%x==0) ans=min(ans,k/x);
	}
	printf("%d",ans);
	return 0;
}