#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

string reqd = "abacaba";
string cur, s;

bool check(int idx)
{
	s = cur;
	for(int i = 0; i < 7; i++)
	{
		if(s[idx + i] == reqd[i])
			continue;
		if(s[idx + i] != '?')
			return 0;
		s[idx + i] = reqd[i];
	}
	int cnt = 0;
	for(int i = 0; i + 6 < s.size(); i++)
		if(s.substr(i, 7) == reqd)
			cnt++;
	for(auto &it:s)
		if(it == '?')
			it = 'z';
	return (cnt == 1);
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cin >> cur;
		int flag = 0;
		for(int i = 0; i + 6 < cur.size(); i++)
		{
			if(check(i))
			{
				flag = 1;
				cout << "Yes" << endl;
				cout << s << endl;
				break;
			}
		}
		if(!flag)
			cout << "No" << endl;
	}
	return 0;
}