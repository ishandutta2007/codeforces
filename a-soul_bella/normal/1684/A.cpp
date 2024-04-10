#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		if(s.size()==2)
		{
			cout << s[1] << "\n";
		}
		else
		{
			char mn='z';
			for(auto t:s) mn=min(mn,t);
			cout << mn << "\n";
		}
	}
	return 0;
}