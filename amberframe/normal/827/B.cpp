#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const int maxn = 2000005;

int n,K;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("load.in","r",stdin);
		//freopen("load.out","w",stdout);
	#endif
	scanf("%d %d",&n,&K);int m=(n-1-K)/K;
	int c=n-1-K-m*K;
	if (c==0) printf("%d\n",2*m+2);
	else if (c==1) printf("%d\n",2*m+3);
	else if (c>=2) printf("%d\n",2*m+4);
	
	int tot=1;
	for (int i=1;i<=c;i++)
	{
		for (int las=1,j=1;j<=m+2;j++)
			{++tot;printf("%d %d\n",las,tot);las=tot;}
	}
	for (int i=c+1;i<=K;i++)
	{
		for (int las=1,j=1;j<=m+1;j++)
			{++tot;printf("%d %d\n",las,tot);las=tot;}
	}
	return 0;
}