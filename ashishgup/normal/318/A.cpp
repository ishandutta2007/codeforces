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
	int even=n/2;
	int odd=(n+1)/2;
	if(k<=odd)
		cout<<2*k-1;
	else
	{
		k-=odd;
		cout<<2*k;
	}
	return 0;
}