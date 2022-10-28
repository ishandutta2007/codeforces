#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;

void printleft()
{
	if(n<6)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		for(int i=2;i<=n/2;i++)
		{
			cout<<"1 "<<i<<endl;
		}
		cout<<"1 "<<n/2 + 1<<endl;	
		for(int i=(n/2 + 2);i<=n;i++)
		{
			cout<<n/2 + 1<<" "<<i<<endl;
		}
	}
}

void printright()
{
	for(int i=2;i<=n;i++)
	{
		cout<<"1 "<<i<<endl;
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	printleft();
	printright();
	return 0;
}