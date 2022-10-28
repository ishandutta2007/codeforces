#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3 + 5;

int n, m, common = 0;
map<string, int> a, b;

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		a[s]++;
	}
	for(int i = 1; i <= m; i++)
	{
		string s;
		cin >> s;
		if(a.count(s))
		{
			common++;
			a.erase(s);
		}
		else
			b[s]++;
	}
	common %= 2;
	if(!common)
	{
		if(a.size() > b.size())
			cout << "YES";
		else
			cout << "NO";
	}
	else
	{
		if(b.size() > a.size())
			cout << "NO";
		else
			cout << "YES";
	}
	return 0;
}