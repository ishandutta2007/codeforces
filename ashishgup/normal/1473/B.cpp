//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int n, d;
int a[N];

string period(string &s, string &t)
{
	int n = s.size();
	for(int i = 0; i < n; i++)
	{
	    if(n % (i + 1) || t.size() % (i + 1))
	        continue;
		string cur = "";
		for(int j = 0; j <= i; j++)
			cur += s[j];
		int flag = 1;
		for(int j = 0; j < n; j++)
			if(s[j] != cur[j % cur.size()])
				flag = 0;
		for(int j = 0; j < t.size(); j++)
			if(t[j] != cur[j % cur.size()])
				flag = 0;
		if(flag)
			return cur;
	}
	return "?";
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		string s, t;
		cin >> s >> t;
		string x = period(s, t);
		if(x.size() > t.size() || x == "?")
			cout << -1 << endl;
		else
		{
			int flag = 1;
			for(int i = 0; i < n; i++)
				if(t[i] != x[i % x.size()])
					flag = 0;
			if(!flag)
				cout << -1 << endl;
			else
			{
				int lcm = s.size() * t.size() / __gcd(s.size(), t.size());
				for(int i = 0; i < lcm; i++)
					cout << x[i % x.size()];
				cout << endl;
			}
		}
	}
	return 0;
}