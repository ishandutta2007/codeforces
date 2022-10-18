#include <bits/stdc++.h>

using namespace std;

#define int long long

string ans;

string find (int x, int y, int a = 0, int b = 1, int c = 1, int d = 0) 
{
	while(y && x)
	{
		if(x < y)
		{
			cout << (y - 1) / x << 'B';
			y %= x;
		}
		else
		{
			cout << (x - 1) / y << 'A';
			x %= y;
		}
	}
}

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void solve()
{
	int x, y;
	cin >> x >> y;
	if(gcd(x, y) != 1)
	{
		cout << "Impossible\n";
		return;
	}
	ans.clear();
	find(x, y);
	cout << ans << "\n";
}

main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	while(t--)
		solve();
	return 0;
}