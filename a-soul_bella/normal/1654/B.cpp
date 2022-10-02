#include <bits/stdc++.h>
#define int long long
using namespace std;
int lst[500];
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
		memset(lst,0,sizeof lst);
		s=' '+s;
		for(int i=1;i<s.size();i++)
			lst[s[i]]=i;
		int mn=1e9;
		for(int i=0;i<=200;i++)
			if(lst[i]) mn=min(mn,lst[i]);
		cout << s.substr(mn) << "\n";
	}
	return 0;
}