#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
int n,m;
bool rev[35];
int main()
{
	int x;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		printf("1\n");
		fflush(stdout);
		scanf("%d",&x);
		if(!x)return 0;
		if(x>0)rev[i]=1;
	}
	int l=2,r=m,mid,i=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		printf("%d\n",mid);
		fflush(stdout);
		scanf("%d",&x);
		if(rev[++i])x=-x;
		if(i==n)i=0;
		if(x>0)r=mid-1;
		else if(x<0)l=mid+1;
		else return 0;
	}
	return 0;
}