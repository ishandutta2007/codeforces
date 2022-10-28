#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	if(n%2)
	{
		cout<<"0";
		return 0;
	}
	n/=2;
	int ans=(n-1)/2;
	cout<<ans;
	return 0;
}