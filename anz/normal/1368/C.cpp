#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	cout << 4 + 3 * n << '\n';

	cout << "0 0\n";
	cout << "0 1\n";
	cout << "1 0\n";
	cout << "1 1\n";

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ' ' << i + 2 << '\n';
		cout << i + 2 << ' ' << i + 1 << '\n';
		cout << i + 2 << ' ' << i + 2 << '\n';
	}
}