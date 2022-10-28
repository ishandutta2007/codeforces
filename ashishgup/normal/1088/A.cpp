#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int x;
	cin>>x;
	for(int a=1;a<=x;a++)
	{
		for(int b=1;b<=x;b++)
		{
			if(a%b==0 && a*b>x && a<x*b)
			{
				cout<<a<<" "<<b;
				return 0;
			}
		}
	}
	cout<<"-1";
	return 0;
}