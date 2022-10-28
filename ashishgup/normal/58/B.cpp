#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;

int32_t main()
{
	IOS;
	cin>>n;
	while(n>1)
	{
		cout<<n<<" ";
		int div=n;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				div=i;
				break;
			}
		}
		n/=div;
	}
	cout<<1;
	return 0;
}