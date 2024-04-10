#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
int pos=0, neg=0;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x, y;
		cin>>x>>y;
		if(x>0)
			pos++;
		else
			neg++;
	}
	if(min(pos, neg)<=1)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}