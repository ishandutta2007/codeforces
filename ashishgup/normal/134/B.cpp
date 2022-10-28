#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int count_gcd(int a, int b) 
{ 
	if(a==1)
		return b-1; 
	if(a>b)
		return count_gcd(b, a);
	if(b%a)
		return b/a + count_gcd(b%a, a); 
	else
		return 1e9;
}

int n;

int32_t main()
{
	IOS;
	cin>>n;
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	int ans=1e9;
	for(int i=1;i<n;i++)
		ans=min(ans, count_gcd(i, n));
	cout<<ans;
	return 0;
}