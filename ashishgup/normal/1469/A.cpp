#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		if(s.size() % 2)
		{
			cout << "NO" << endl;
			continue;
		}
		if(s[0] == ')' || s.back() == '(')
		{
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
	return 0;
}