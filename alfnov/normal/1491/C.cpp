#include<bits/stdc++.h>
using namespace std;
int s[5005],d[5005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&s[i]),ans+=s[i]-1;
		for(int i=1;i<=n;i++)
		{
			int r=d[i-1];
			for(int j=1;j<i-1;j++)if(j+s[j]>=i)r++;
			ans-=min(r,s[i]-1);
			d[i]=max(0,r-min(r,s[i]-1));
		}
		cout<<ans<<endl;
	}
	return 0;
}