#include<bits/stdc++.h>
using namespace std;
int s[1000005],d[1000005],tot=0;
void print()
{
	s[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!s[i])d[++tot]=i;
		for(int j=1;i*d[j]<=1000000;j++)
		{
			s[i*d[j]]=1;
			if(i%d[j]==0)break;
		}
	}
}
int main()
{
	print();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long ans=1;
		int wz=1;
		for(int i=2;i<=3;i++)
		{
			wz=d[lower_bound(d+1,d+tot+1,wz+n)-d];
			ans=ans*wz;
		}
		cout<<ans<<endl;
	}
	return 0;
}