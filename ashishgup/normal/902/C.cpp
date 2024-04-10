#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int  h;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin>>h;
	for(int i=0;i<=h;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		if(i>=1)
			b[i]+=b[i-1];
	}
	int check=true;
	int store=-1;
	for(int i=0;i<=h-1;i++)
	{	
		if(a[i]>=2&&a[i+1]>=2)
		{
			store=i+1;
			check=false;
			break;
		}
	}	
	if(check)
	{
		cout<<"perfect";
		return 0;
	}
	cout<<"ambiguous"<<endl;
	cout<<"0 ";
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<b[i-1]<<" ";
		}
	}
	cout<<endl;
	cout<<"0 ";
	for(int i=1;i<=h;i++)
	{
		if(i!=store)
		{
			for(int j=1;j<=a[i];j++)
			{
				cout<<b[i-1]<<" ";
			}
		}
		else
		{
			for(int j=1;j<=a[i]-1;j++)
			{
				cout<<b[i-1]<<" ";
			}
			cout<<b[i-1]-1<<" ";
		}
	}
	return 0;
}