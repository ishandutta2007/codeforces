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
		int flag=0;
		for(int i=s.size()-1;i>=1;i--)
		{
			if(s[i]-'0'+s[i-1]-'0'>=10)
			{
				cout << s.substr(0,i-1);
				cout << s[i]-'0'+s[i-1]-'0';
				cout << s.substr(i+1);
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			cout << s[1]-'0'+s[0]-'0';
			if(s.size()>2) cout << s.substr(2);
		}
		cout << "\n";
	}
	return 0;
}