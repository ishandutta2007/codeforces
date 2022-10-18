#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int gcd(int a,int b)
{
	int t;
	while(b) t=a%b,a=b,b=t;
	return a;
}

int abs(int a)
{
	if(a<0) return -a;
	return a;
}

int num[100000];

int main()
{
	int n,i,g,a,b,ans=0;
	scanf("%d%d",&n,&num[0]),g=num[0];
	for(i=1;i<n;i++) scanf("%d",&num[i]),g=gcd(g,num[i]);
	if(g>1)
	{
		printf("YES\n0\n");
		return 0;
	}
	for(i=0;i<n;i++) num[i]%=2;
	for(i=0;i<n-1;i++)
		if(num[i]+num[i+1]==2) ans++,num[i]=num[i+1]=0;
	for(i=0;i<n-1;i++)
		if(num[i]+num[i+1]==1) ans+=2,num[i]=num[i+1]=0;
	printf("YES\n%d\n",ans);
}