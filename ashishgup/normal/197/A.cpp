#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int a, b, r;
	cin>>a>>b>>r;
	if(2*r<=a && 2*r<=b)
		cout<<"First";
	else
		cout<<"Second";
	return 0;
}