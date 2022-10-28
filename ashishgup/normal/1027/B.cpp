#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int n, q;
	cin>>n>>q;
	while(q--)
	{
		int x, y;
		cin>>x>>y;
		if((x+y)%2==0)
		{
			int rows=x-1;
			int oddrows=(rows+1)/2;
			int evenrows=(rows)/2;
			int cur=oddrows*((n+1)/2) + evenrows*(n/2);
			int seg=(y+1)/2;
			cur+=seg;
			cout<<cur<<endl;
		}
		else
		{
			int rows=x-1;
			int oddrows=(rows+1)/2;
			int evenrows=(rows)/2;
			int cur=oddrows*((n)/2) + evenrows*((n+1)/2);
			cur+=(y+1)/2;
			cur+=(n*n+1)/2;
			cout<<cur<<endl;
		}
	}
	return 0;
}