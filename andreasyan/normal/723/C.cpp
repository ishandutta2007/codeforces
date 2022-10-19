#include <iostream>
using namespace std;

int a[2002],b[2002],n,m,k,t;
int main()
{
	int i,j;
	cin>>n>>m;
	k=n/m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<=m)
			b[a[i]]++;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>m)
		{
			for(j=1;j<=m;j++)
			{
				if(b[j]<k)
				{
					b[j]++;
					a[i]=j;
					t++;
					break;
				}
			}
		}
		if(a[i]<=m && b[a[i]]>k)
		{
			for(j=1;j<=m;j++)
				if(b[j]<k)
				{
					b[j]++;
					b[a[i]]--;
					a[i]=j;
					t++;
					break;
				}
		}
	}
	cout<<k<<' '<<t<<endl;
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
}