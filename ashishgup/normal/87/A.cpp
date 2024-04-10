#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
	int a, b;
	cin>>a>>b;
	int period=lcm(a, b);
	int left=period/a - 1;
	int right=period/b - 1;
	if(a<b)
		right++;
	else
		left++;
	if(left<right)
		cout<<"Masha";
	else if(left>right)
		cout<<"Dasha";
	else
		cout<<"Equal";
    return 0;
}