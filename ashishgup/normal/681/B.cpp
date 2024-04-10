#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=0;i*1234567<=n;i++)
	{
		for(int j=0;j*123456<=n;j++)
		{
			int k=n-i*1234567-j*123456;
			if(k<0)
				break;
			if(k%1234==0)
			{
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}