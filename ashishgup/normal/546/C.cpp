#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k1, k2;
deque<int> a, b;

int32_t main()
{
	IOS;
	cin >> n;
	cin >> k1;
	for(int i = 1; i <= k1; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	cin >> k2;
	for(int i = 1; i <= k2; i++)
	{
		int x;
		cin >> x;
		b.push_back(x);
	}
	for(int i = 1; i <= 1e6; i++)
	{
		int x = a.front();
		int y = b.front();
		a.pop_front();
		b.pop_front();
		if(x > y)
		{
			a.push_back(y);
			a.push_back(x);
		}
		else
		{
			b.push_back(x);
			b.push_back(y);
		}
		if(!a.size())
		{
			cout << i << " " << 2;
			return 0;
		}
		if(!b.size())
		{
			cout << i << " " << 1;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}