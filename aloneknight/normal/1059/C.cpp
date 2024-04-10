#include<bits/stdc++.h>
using namespace std;
int n,num[1000005];
int main()
{
	scanf("%d",&n);
	if(n==1){puts("1");return 0;}
	int gg=1,cc=0;
	for(int i=1;i<=n;i++)num[i]=n-n/i;
	while(true)
	{
		int c=0;
		for(int i=2;1ll*i*gg<=n;i++)if(!c||num[c]>=num[i*gg])c=i*gg;
		if(c)
		{
			for(int i=cc+1;i<=num[c];i++)printf("%d ",gg);
			cc=num[c];gg=c;
		}
		if(cc==n-1)break;
	}
	printf("%d\n",gg);
	return 0;
}