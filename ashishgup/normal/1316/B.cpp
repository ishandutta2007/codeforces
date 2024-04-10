#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e5 + 5;

int n;
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		string ans = s;
		int k = 1;
		for(int i = 1; i + 1 < n; i++)
		{
			string cur = "";
			for(int j = i; j < n; j++)
				cur += s[j];
			if((i + 1) % 2 != n % 2)
				for(int j = 0; j < i; j++)
					cur += s[j];
			else
				for(int j = i - 1; j >= 0; j--)
					cur += s[j];
			if(cur < ans)
			{
				k = i + 1;
				ans = cur;
			}
		}
		reverse(s.begin(), s.end());
		if(s < ans)
		{
			ans = s;
			k = n;
		}
		cout << ans << endl;
		cout << k << endl;
	}
	return 0;
}