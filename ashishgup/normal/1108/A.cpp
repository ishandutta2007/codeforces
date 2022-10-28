#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		int l1, r1, l2, r2;
		cin>>l1>>r1>>l2>>r2;
		int x=l1, y;
		if(l2==l1)
			y=l2+1;
		else
			y=l2;
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}