#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		bool check = 1;
		for(int i = 1; i < s.size(); i++)
		{
			if(s[i] != s[i - 1] + 1)
				check = 0;
		}
		if(check)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}