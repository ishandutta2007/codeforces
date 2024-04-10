#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, k, ans=0;

int32_t main()
{
	IOS;
	cin>>n>>k;
	n--;
	for(int i=1;i<=k && n>0;i++)
	{
		ans+=(2*n-1);
		n-=2;
	}
	cout<<ans;
	return 0;	
}