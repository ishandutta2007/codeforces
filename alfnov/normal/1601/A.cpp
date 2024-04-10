#include<bits/stdc++.h>
using namespace std;
int a[200005],he[2005];
int main()
{
	int T=1;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=0;i<=30;i++)he[i]=0;
		for(int i=1;i<=n;i++)for(int j=0;j<=30;j++)
			if(a[i]&(1<<j))he[j]++;
		for(int i=1;i<=n;i++)
		{
			int flag=1;
			for(int j=0;j<=30;j++)if(he[j]%i)flag=0;
			if(flag)printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}