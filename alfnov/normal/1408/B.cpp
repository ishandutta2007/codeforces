#include<bits/stdc++.h>
using namespace std;
int a[100005],xx[105];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int temp=300;
		while(temp--)
		{
			int gs=0,wz=n+1;
			memset(xx,0,sizeof(xx));
			for(int i=1;i<=n;i++)
			{
				if(!xx[a[i]])gs++;
				xx[a[i]]++;
				if(gs>k)
				{
					wz=i-1;
					break;
				}
			}
			if(wz==n+1)
			{
				cout<<300-temp<<endl;
				break;
			}
			int tt=a[wz];
			for(int i=1;i<=n;i++)a[i]=max(0,a[i]-tt);
		}
		if(temp<0)puts("-1");
	}
	return 0;
}