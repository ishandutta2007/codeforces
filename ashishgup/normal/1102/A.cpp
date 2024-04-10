#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int sum=n*(n+1)/2;
	if(sum%2)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}