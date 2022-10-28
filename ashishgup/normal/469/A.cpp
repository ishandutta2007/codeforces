#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
set<int> s;

int32_t main()
{
    IOS;
	cin>>n;
	for(int i=1;i<=2;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int cur;
			cin>>cur;
			s.insert(cur);
		}
	}  
	if(s.size()==n)
		cout<<"I become the guy.";
	else
		cout<<"Oh, my keyboard!";
	return 0;
}