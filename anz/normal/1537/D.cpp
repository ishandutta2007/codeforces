#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector <int> lose;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 1; i < 30; i += 2) lose.push_back(1 << i);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;

		if (n % 2 == 1)
		{
			cout << "Bob\n";
			continue;
		}

		if (binary_search(lose.begin(), lose.end(), n))
			cout << "Bob\n";
		else cout << "Alice\n";
	}
}