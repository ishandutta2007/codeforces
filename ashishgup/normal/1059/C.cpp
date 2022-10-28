#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int cur=1;
	while(n>1)
	{
		int twos=n/2, threes=n/3;
		if(twos>threes)
		{
			for(int i=1;i<=n-twos;i++)
				cout<<cur<<" ";
			cur*=2;
			n=twos;
		}
		else
		{
			for(int i=1;i<=n-threes;i++)
				cout<<cur<<" ";
			cur*=3;
			n=threes;
		}
	}
	cout<<cur;
	return 0;
}