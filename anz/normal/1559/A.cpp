#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;

		for (int i = 0; i < n; i++) cin >> a[i];

		int ans = a[0];
		for (int i = 1; i < n; i++) ans &= a[i];

		cout << ans << '\n';
	}
}