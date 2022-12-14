#include<iostream>
#include<cstdio>
using namespace std;
int a[5050],b[5050];
int c[5050],d[5050];
int v[5050],p[5050];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,ans=0;
	cin>>n;
	if(n&1)
	{
		for(int i=0;i<n;i++)
		{
			cout<<"? "<<i<<" "<<0<<endl;
			fflush(stdout);
			cin>>a[i];
		}
		int tmp=0;
		for(int i=0;i<n;i++)
			tmp^=i;
		for(int i=0;i<n;i++)
			tmp^=a[i];
		cout<<"!"<<endl<<1<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<(a[i]^tmp);
			if(i!=n-1)
				cout<<" ";
		}
		cout<<endl;
		fflush(stdout);
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cout<<"? "<<i<<" "<<0<<endl;
			fflush(stdout);
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			cout<<"? "<<0<<" "<<i<<endl;
			fflush(stdout);
			cin>>b[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				c[j]=a[j]^i;
			for(int j=0;j<n;j++)
				d[j]=c[0]^b[j];
			bool flag=0;
			for(int j=0;j<n;j++)
				v[j]=0;
			for(int j=0;j<n;j++)
				v[c[j]]++;
			for(int j=0;j<n;j++)
			if(v[j]!=1)
			{
				flag=1;
				break;
			}
			if(flag)
				continue;
			for(int j=0;j<n;j++)
				v[j]=0;
			for(int j=0;j<n;j++)
				v[d[j]]++;
			for(int j=0;j<n;j++)
			if(v[j]!=1)
			{
				flag=1;
				break;
			}
			if(flag)
				continue;
			for(int j=0;j<n;j++)
			if(d[c[j]]!=j)
			{
				flag=1;
				break;
			}
			if(flag)
				continue;
			ans++;
			for(int j=0;j<n;j++)
				p[j]=c[j];
		}
		cout<<"!"<<endl<<ans<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<p[i];
			if(i!=n-1)
				cout<<" ";
		}
		cout<<endl;
		fflush(stdout);
	}
	return 0;
}