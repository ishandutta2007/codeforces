#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int N=200;

long long n,m;
int ans[N],a[N];
int c[N];
int main()
{
	int i,j,k=0;
	cin>>n>>m;
	for(i=0;i<m;++i)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	for(i=0;i<m-1;++i)
	{
		int u;
		if(a[i+1]-a[i]>0)
			u=a[i+1]-a[i];
		else
			u=(n-a[i])+a[i+1];
		if(ans[a[i]])
		{
			if(u!=ans[a[i]])
			{
				cout<<"-1"<<endl;
				return 0;
			}
		}
		ans[a[i]]=u;
	}
	for(i=1;i<=n;++i)
	{
		if(ans[i]>n)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		c[ans[i]]++;
	}
	for(i=1;i<=n;++i)
	{
		if(ans[i]==0)
		{
			for(j=1;j<=n;++j)
				if(c[j]==0)
				{
					ans[i]=j;
					break;
				}
			c[j]++;
		}
		if(c[i]>1)
		{
			cout<<"-1"<<endl;
			return 0;
		}
	}
	for(i=1;i<=n;++i)
		cout<<ans[i]<<' ';
	cout<<endl;
//	system("pause");
	return 0;
}