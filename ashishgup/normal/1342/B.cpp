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
		string s;
		cin >> s;
		map<char, int> m;
		for(auto &it:s)
			m[it]++;
		if(m.size() == 1)
			cout << s << endl;
		else
		{
			for(int i = 0; i < 2 * s.size(); i++)
				cout << i % 2;
			cout << endl;
		}
	}
	return 0;
}