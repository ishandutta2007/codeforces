#include<bits/stdc++.h>
using namespace std;
int f[105],q[105],a[105],b[105];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,tot=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
			if(b[i]==0)
			{
				f[++tot]=i;
				q[tot]=a[i];
			}
		}
		sort(q+1,q+tot+1,greater<int>());
		for(int i=1;i<=tot;i++)a[f[i]]=q[i];
		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		puts("");
	}
	return 0;
}