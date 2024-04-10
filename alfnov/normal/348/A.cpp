#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	long long l=1,r=1e15;
	while(l<=r)
	{
		long long mid=l+r>>1,cs=0;
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			cs+=mid-a[i];
			if(cs>=mid)
			{
				flag=1;
				break;
			}
		}
		for(int i=1;i<=n;i++)flag&=(mid>=a[i]);
		if(flag)r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}