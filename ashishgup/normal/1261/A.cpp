#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k;
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		cin >> s;
		vector<pair<int, int > > v;
		for(int i = 0; i < 2 * k - 2; i++)
		{
			char ch = '(';
			if(i % 2)
				ch = ')';
			for(int j = i; j < n; j++)
			{
				if(s[j] == ch)
				{
					v.push_back({i, j});
					reverse(s.begin() + i, s.begin() + j + 1);
					break;
				}
			}	
		}
		int rem = (n - 1 - (2 * k - 2) + 1) / 2;
		for(int i = 2 * k - 2; i < n; i++)
		{
			char ch = '(';
			if(rem <= 0)
				ch = ')';
			rem--;
			for(int j = i; j < n; j++)
			{
				if(s[j] == ch)
				{
					v.push_back({i, j});
					reverse(s.begin() + i, s.begin() + j + 1);
					break;
				}
			}	
		}
		cout << v.size() << endl;
		for(auto &it:v)
			cout << it.first + 1 << " " << it.second + 1 << endl;
	}
	return 0;
}