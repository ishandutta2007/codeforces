#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int flag=0;
		for(int i=30;i>=0;i--)
		{
			int c1=0,c2=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j]&(1<<i))c1++;
				else c2++;
			}
			if(!(c1&1))continue;
			flag=1;
			if((c1&3)==1)printf("WIN\n");
			else if(c2&1)printf("WIN\n");
			else printf("LOSE\n");
			break;
		}
		if(!flag)printf("DRAW\n");
	}
	return 0;
}