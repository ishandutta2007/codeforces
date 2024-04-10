#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	cout<<n+n/2<<endl;
	for(int i=2;i<=n;i+=2)
		cout<<i<<" ";
	for(int i=1;i<=n;i+=2)
		cout<<i<<" ";
	for(int i=2;i<=n;i+=2)
		cout<<i<<" ";
	return 0;
}