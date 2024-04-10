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
	if(n==1)
	{
		cout<<"-1";
		return 0;
	}
	cout<<n<<" "<<(n+1)<<" "<<(n*(n+1));
	return 0;
}