#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
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
		if(s.back()=='A')
		{
			cout << "NO\n";
			continue;
		}
		int cnt=0,flag=1;
		for(auto t:s)
		{
			if(t=='A') ++cnt;
			else --cnt;
			if(cnt<0)
			{
				flag=0;
				break;
			}
		}
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}