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
	int min1=2*(n/7);
	min1+=max(0LL, n%7 - 5);
	int max1=2*(n/7);
	max1+=min(2LL, n%7);
	cout<<min1<<" "<<max1;
	return 0;
}