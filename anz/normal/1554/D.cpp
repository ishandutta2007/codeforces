#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		int n; cin >> n;
		if (n == 1)
		{
			cout << "a\n";
			continue;
		}

		for (int i = 0; i < n / 2; i++) cout << 'a';
		cout << 'b';
		for (int i = 0; i < n / 2 - 1; i++) cout << 'a';
		if (n % 2) cout << 'c';
		cout << '\n';
	}
}