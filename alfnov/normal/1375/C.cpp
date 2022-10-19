#include<bits/stdc++.h>
using namespace std;
int a[300005],p[300005],q[300005],b[300005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
			p[a[i]]=i;
		}
		b[n+1]=0;
		for(int i=n;i>=1;i--)b[i]=max(b[i],b[i+1]);
		int zz=1;
		int nn=1;
		q[nn]=1;
		while(zz!=n)
		{
			zz=p[b[zz+1]];
			q[++nn]=zz;
		}
		n=nn;
		for(int i=1;i<=n;i++)b[i]=a[q[i]];
		for(int i=1;i<=n;i++)a[i]=b[i];
		int tt=n+1;
		for(int i=1;i<=n;i++)if(a[i]<a[1])
		{
			tt=i;
			break;
		}
		if(tt>n)
		{
			cout<<"YES"<<endl;
		}else
		{
			int flag=0;
			for(int i=tt;i<=n;i++)if(a[i]>a[1])flag=1;
			if(flag)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}