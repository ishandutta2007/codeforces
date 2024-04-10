#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int nC5(int n)
{
	int ans=n*(n-1)*(n-2)*(n-3)*(n-4)/120;
	return ans;
}

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int ans=120*nC5(n)*nC5(n);
	cout<<ans;
	return 0;
}