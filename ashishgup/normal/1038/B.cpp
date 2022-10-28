#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	if(n<=2)
	{
		cout<<"No";
		return 0;
	}
	else
	{
		cout<<"Yes"<<endl;
		int k=(n%2==0)?(n/2):((n+1)/2);
		cout<<"1 "<<k<<endl;
		cout<<n-1<<" ";
		for(int i=1;i<=n;i++)
		{
			if(i==k)
				continue;
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}