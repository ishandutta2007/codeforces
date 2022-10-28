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
		vector<string> ans;
		int n = s.size();
		for(int i = 0; i < n; i++)
		{
			if(s[i] > '0')
			{
				string cur = "";
				cur += s[i];
				for(int j = i + 1; j < n; j++)
					cur += '0';
				ans.push_back(cur);
			}
		}
		cout << ans.size() << endl;
		for(auto &it:ans)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}