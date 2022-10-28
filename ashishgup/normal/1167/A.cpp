#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool check = 0;
		for(int i = 0; i + 10 < s.size(); i++)
			check |= (s[i] == '8');
		if(check)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}