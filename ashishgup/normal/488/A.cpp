#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int check(int x)
{
	x=abs(x);
	while(x>0)
	{
		if(x%10==8)
			return 1;
		x/=10;
	}
	return 0;
}

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	n++;
	int ans=1;
	while(!check(n))
		n++, ans++;
	cout<<ans;
	return 0;
}