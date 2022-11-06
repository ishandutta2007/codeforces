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

	int T; cin >> T;
	while (T--)
	{
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		cout << ((a[0] + a[1] + a[2]) % 3 ? 1 : 0) << '\n';
	}
}