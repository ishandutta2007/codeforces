#include<bits/stdc++.h>
using namespace std;
int h[105];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)scanf("%d",&h[i]);
		if(k>10000)
		{
			puts("-1");
			continue;
		}
		int flag=1,wz=0;
		for(int i=1;i<=k;i++)
		{
			int j;
			for(j=1;j<n;j++)
			{
				if(h[j]<h[j+1])
				{
					h[j]++;
					break;
				}
			}
			if(j==n)
			{
				puts("-1");
				flag=0;
				break;
			}
			wz=j;
		}
		if(flag)cout<<wz<<endl;
	}
	return 0;
}