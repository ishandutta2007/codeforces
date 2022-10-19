#include<bits/stdc++.h>
using namespace std;
int a[200005],f[200005][2];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)f[i][0]=f[i][1]=1000000000;
		f[1][0]=a[1],f[2][0]=a[1]+a[2],f[2][1]=f[1][0];
		for(int i=3;i<=n;i++)
		{
			f[i][0]=min(f[i][0],f[i-1][1]+a[i]);
			f[i][0]=min(f[i][0],f[i-2][1]+a[i-1]+a[i]);
			f[i][1]=min(f[i][1],f[i-1][0]);
			f[i][1]=min(f[i][1],f[i-2][0]);
		}
		cout<<min(f[n][0],f[n][1])<<endl;
	}
	return 0;
}