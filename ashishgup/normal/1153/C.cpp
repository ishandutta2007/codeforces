#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
string s;

int32_t main()
{
	IOS;
	cin >> n >> s;
	if(s.size() == 2)
	{
		if(s[0] == ')' || s[1] == '(')
		{
			cout << ":(";
			exit(0);
		}
		else
		{
			cout << "()";
			exit(0);
		}
	}
	if(s.size() % 2)
	{
		cout << ":(";
		exit(0);
	}
	if(s[0] == ')' || s[1] == ')' || s[n - 1] == '(' || s[n - 2] == '(')
	{
		cout << ":(";
		exit(0);
	}
	s[0] = '(';
	s[1] = '(';
	s[n - 2] = ')';
	s[n - 1] = ')';
	int cur = 1, have = 0;
	for(int i = 2; i < n - 2; i++)
	{
		if(s[i] == '(')
			cur++;
		else if(s[i] == ')')
			cur--;
		else
			have++;
		if(cur + have <= -1)
		{
			cout << ":(";
			exit(0);
		}
	}
	int mx = cur + have;
	int mn = cur - have;
	if(mn <= 1 && 1 <= mx)
	{
		int reqd = 1 - cur;
		int use = abs(reqd);
		if((have - use) % 2)
		{
			cout << ":(";
			exit(0);
		}
		else
		{
			int open = (have - use) / 2;
			if(reqd > 0)
				open += reqd;
			int close = (have - use) / 2;
			if(reqd < 0)
				close += abs(reqd);
			for(int i = 0; i < n; i++)
			{
				if(s[i] != '?');
				else
				{
					if(open > 0)
						s[i] = '(', open--;
					else
						s[i] = ')';
				}
			}
			int bal = 0;
			for(int i = 0; i < n; i++)
			{
				if(s[i] == '(')
					bal++;
				else
					bal--;
				if(bal == 0 && i != n - 1)
				{
					cout << ":(";
					exit(0);
				}
				if(i == n - 1 && bal != 0)
				{
					cout << ":(";
					exit(0);
				}
			}
			cout << s;
		}
	}
	else
	{
		cout << ":(";
		exit(0);
	}
	return 0;
}