#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

bool b[6];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s; cin >> s;
	for (char c : s)
	{
		if (c == '0')
		{
			if (!b[0]) cout << "1 1\n", b[0] = 1;
			else if (!b[1]) cout << "3 1\n", b[1] = 1;
		}
		else
		{
			if (!b[2]) cout << "1 3\n", b[2] = 1;
			else if (!b[3]) cout << "2 3\n", b[3] = 1;
			else if (!b[4]) cout << "3 3\n", b[4] = 1;
			else cout << "4 3\n", b[5] = 1;
		}

		if (b[0] && b[1]) b[0] = b[1] = 0;
		if (b[2] && b[3] && b[4] && b[5]) b[2] = b[3] = b[4] = b[5] = 0;
	}
}