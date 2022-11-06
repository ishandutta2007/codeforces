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

	int a; cin >> a;
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			cout << i << a / i << '\n';
			return 0;
		}
	}
}