#include <bits/stdc++.h>
#define mod 1000000007
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
		string s,t;
		cin >> s >> t;
		int flag=0;
		for(auto x:t) if(x=='a') flag=1;
		if(t.size()==1&&flag)
		{
			cout << 1 << "\n";
			continue;
		}
		if(t.size()>1&&flag)
		{
			cout << "-1\n";
			continue;
		}
		cout << (1ll<<s.size()) << "\n";
	}
	return 0;
}