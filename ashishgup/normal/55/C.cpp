#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int32_t main()
{
	IOS;
	int n, m, k;
	cin>>n>>m>>k;
	int check=0;
	for(int i=1;i<=k;i++)
	{
		int x, y;
		cin>>x>>y;
		if(x<=5||y<=5||(n-x+1)<=5||(m-y+1)<=5)
			check=1;
	}
	if(check)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}