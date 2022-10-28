#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	string s;
	cin >> s;
	int n = s.size();
	string reqd = "";
	int idx;
	int leftover = 0;
	bool check = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if(s[i] == 'a')
		{
			for(int j = 0; j < i; j++)
			{
				if(s[j] != 'a')
					reqd += s[j];
			}
			leftover = n - 1 - i;
			check = 1;
			idx = i + 1;
			break;
		}
	}
	if(!check)
	{
		if(s.size() % 2)
		{
			cout << ":(";
			return 0;
		}
		int i = 0, j = s.size() / 2;
		for(; j < s.size(); i++, j++)
		{
			if(s[i] != s[j])
			{
				cout << ":(";
				return 0;
			}
		}
		cout << s.substr(0, s.size() / 2);
		return 0;
	}
	if(leftover < reqd.size())
	{
		cout << ":(";
		exit(0);
	}
	int need = reqd.size();
	if((leftover - need) % 2)
	{
		cout << ":(";
		exit(0);
	}
	int match = (leftover - need) / 2;
	int store = match;
	for(int i = idx, j = n - match; match > 0; i++, j++, match--)
	{
		if(s[i] != s[j])
		{
			cout << ":(";
			return 0;
		}
	}
	match = store;
	for(int i = 0, j = idx + match; i < reqd.size(); i++, j++)
	{
		if(reqd[i] != s[j])
		{
			cout << ":(";
			return 0;
		}
	}
	cout << s.substr(0, idx + match);
	return 0;
}