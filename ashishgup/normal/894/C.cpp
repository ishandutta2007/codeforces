#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e3+5;

int n;
int a[N];

int32_t main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]%a[1]!=0)
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<2*n<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" "<<a[1]<<" ";
	}
}