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
		map<char, int> cnt;
		int ans = 0;
		for(auto &it:s)
		{
			if(it == ')' && cnt['('] > 0)
					ans++, cnt['(']--;
			else if(it == ']' && cnt['['] > 0)
					ans++, cnt['[']--;
			else
				cnt[it]++;
		}
		cout << ans << endl;
	}
	return 0;
}