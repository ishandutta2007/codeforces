#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
string s;

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		int x = 0, y = 0;
		while(s.size() && s.back()=='>')
		{
			s.pop_back();
			x++;
		}
		reverse(s.begin(), s.end());
		while(s.size() && s.back()=='<')
		{
			s.pop_back();
			y++;
		}
		cout<<min(x, y)<<endl;
	}
	return 0;
}