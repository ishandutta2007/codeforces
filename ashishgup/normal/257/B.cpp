#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, m;

int32_t main()
{
	IOS;
	cin>>n>>m;
	int total=n+m-1;
	cout<<total-min(n, m)<<" "<<min(n, m);
	return 0;
}