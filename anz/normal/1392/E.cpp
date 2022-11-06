#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
ll board[26][26];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j += 2)
	{
		board[i][j] = (1ll << (i + j));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cout << board[i][j] << ' ';
		cout << endl;
	}

	int q; cin >> q;
	while (q--)
	{
		ll k; cin >> k;
		cout << "1 1" << endl;
		int cx = 1, cy = 1;
		int curBit = 1;
		for (int i = 0; i < n * 2 - 2; i++)
		{
			k /= 2;
			if (curBit == k % 2) cout << ++cx << ' ' << cy << endl;
			else cout << cx << ' ' << ++cy << endl;

			curBit = k % 2;
		}
	}
}