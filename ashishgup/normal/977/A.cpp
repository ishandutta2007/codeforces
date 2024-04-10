#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int n, k;
	cin>>n>>k;
	while(k--)
	{
		if(n%10)
			n-=1;
		else
			n/=10;
	}
	cout<<n;
	return 0;
}