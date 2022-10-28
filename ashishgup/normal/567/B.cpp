#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int ans=0;
set<int> s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int id;
		char ch;
		cin>>ch>>id;
		if(ch=='+')
			s.insert(id);
		else
		{
			if(s.find(id)==s.end())
				ans++;
			else
				s.erase(id);
		}
		ans=max(ans, (int)s.size());
	}	
	cout<<ans;
	return 0;
}