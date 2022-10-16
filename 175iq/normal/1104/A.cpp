#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int n;
	cin>>n;

	int x,y;
	if(n<=9)
	{
		cout<<1<<endl;
		cout<<n;
	}
	else
	{
		if(n%2==0)
		{
			x=n/2;
			cout<<x<<endl;
			for (int i = 0; i < x; ++i)
			{
				cout<<2<<" ";
			}
		}
		else if(n%9==0)
		{
			x=n/9;
			cout<<x<<endl;
			for (int i = 0; i < x; ++i)
			{
				cout<<9<<" ";
			}			
		}
		else if(n%3==0)
		{
			x=n/3;
			cout<<x<<endl;
			for (int i = 0; i < x; ++i)
			{
				cout<<3<<" ";
			}
		}
		else if(n%5==0)
		{
			x=n/5;
			cout<<x<<endl;
			for (int i = 0; i < x; ++i)
			{
				cout<<5<<" ";
			}			
		}
		else if(n%7==0)
		{
			x=n/7;
			cout<<x<<endl;
			for (int i = 0; i < x; ++i)
			{
				cout<<7<<" ";
			}			
		}
		else
		{
			x=n;
			cout<<x<<endl;
			for (int i = 0; i < x; ++i)
			{
				cout<<1<<" ";
			}
		}
	}
	return 0;
}