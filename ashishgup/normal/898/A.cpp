#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=n,j=n;;i--,j++)
	{
		if(i%10==0)
		{
			cout<<i;
			return 0;
		}
		if(j%10==0)
		{
			cout<<j;
			return 0;
		}
	} 
   	return 0;
}