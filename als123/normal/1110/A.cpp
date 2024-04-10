#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
int tot;
int b,k,x; 
int main()
{
	scanf("%d%d",&b,&k);
	int tot=0;
	for (int u=1;u<k;u++)
	{
		scanf("%d",&x);
		tot=tot+(x&1)*(b&1);
	}
	scanf("%d",&x);
	tot=tot+(x&1);
	if (tot&1) printf("odd");
	else printf("even");
	return 0;
}