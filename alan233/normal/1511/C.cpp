#include<bits/stdc++.h>
using namespace std;

int a[300006];

int main()
{
	int n,q,t,x;
	cin>>n>>q;
	for(int i =0;i<n;++i)
	{
		cin>>a[i];
	}
	for(int i =0;i<q;++i)
	{
		cin>>t;
		for(int j =0;j<n;++j)
		{
			if(t==a[j])
			{
				cout<<j+1<<' ';
				x =j;
				break;
			}
		}
		for(int k=x;k>0;k--) // 
		{
			a[k]=a[k-1];
		}
		a[0]=t;
	}
	cout<<endl;
	return 0;
}