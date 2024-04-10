#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m;
set<int> b, g;

int32_t main()
{
	IOS;
	cin >> n >> m;
	int x;
	cin >> x;
	for(int i = 1; i <= x; i++)
	{
		int y; 
		cin >> y;
		b.insert(y);
	}
	cin >> x;
	for(int i = 1; i <= x; i++)
	{
		int y; 
		cin >> y;
		g.insert(y);
	}
	for(int i = 0; i <= 1e6; i++)
	{	
		int bn = i % n;
		int gn = i % m;
		if(b.find(bn) != b.end() || g.find(gn) != g.end())
		{
			b.insert(bn);
			g.insert(gn);
		}
	}	
	if(b.size() == n && g.size() == m)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}