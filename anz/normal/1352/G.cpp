#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int last[6][10] =
{
	{3,1,4,2},
	{1,4,2,5,3},
	{1,4,2,6,3,5},
	{1,4,2,6,3,5,7},
	{1,4,2,6,8,5,3,7},
	{1,4,2,6,8,5,3,7,9}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		if (n < 4)
		{
			cout << "-1\n";
			continue;
		}

		int c = 0;
		while (n >= 10)
		{
			for (int i = 0; i < 6; i++) cout << c * 6 + last[2][i] << ' ';
			c++;
			n -= 6;
		}

		for (int i = 0; i < n; i++) cout << c * 6 + last[n - 4][i] << ' ';
		cout << '\n';
	}
}