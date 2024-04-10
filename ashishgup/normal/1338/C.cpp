#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int getFirst(int n)
{
	int cur = 1;
	while(cur * 4 <= n)
		cur *= 4;
	n -= cur;
	int ans = cur + n / 3;
	return ans;
}

bool update(int &n, int &l, int x, int y)
{
	if(n > x)
	{
		n -= x;
		l += y;
		return 1;
	}
	return 0;
}

int getThird(int n)
{
	int cur = 3, have = 1;
	while(have < n)
	{
		n -= have;
		have *= 4, cur *= 4;
	}
	int l = cur;
	while(have > 1)
	{
		if(update(n, l, (have / 4) * 3, have / 2))
		{

		}
		else if(update(n, l, (have / 4) * 2, have / 4))
		{

		}
		else if(update(n, l, (have / 4) * 1, have / 4 * 3))
		{

		}
		have /= 4;
	}
	return l;
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
		if(n <= 3)
		{
			cout << n << endl;
			continue;
		}
		else if(n % 3 == 1)
			cout << getFirst(n) << endl;
		else if(n % 3 == 0)
			cout << getThird(n / 3) << endl;
		else
			cout << (getFirst(n - 1) ^ getThird((n + 1) / 3)) << endl;
	}
	return 0;
}