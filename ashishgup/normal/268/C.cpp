#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n, m;
	cin>>n>>m;
	int x=n, y=0;
	cout<<min(n, m)+1<<endl;
	for(int i=0;i<=min(n, m);i++)
	{
		cout<<x-i<<" "<<y+i<<endl;
	}
	return 0;
}