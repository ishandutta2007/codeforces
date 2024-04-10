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
		int n = s.size();
		vector<int> v;
		vector<pair<char, int> > v2;
		for(int i = 0; i + 2 < n; i++)
		{
			if(s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e')
			{
				s[i + 1] = 'z';
				v.push_back(i + 1 + 1);
			}
			if(s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
			{
				if(i + 4 < n && s[i + 3] == 'n' && s[i + 4] == 'e')
				{
					s[i + 2] = 'z';
					v.push_back(i + 2 + 1);
				}
				else
				{
					s[i + 1] = 'z';
					v.push_back(i + 1 + 1);
				}
			}
		}
		cout << v.size() << endl;
		for(auto &it:v)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}