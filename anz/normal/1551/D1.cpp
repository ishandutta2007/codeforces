#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, k;
int ans[101][101];

void printAns()
{

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> m >> k;

		bool ans = true;

		if (n % 2 == 1)
		{
			int h = m / 2;
			if (k < h) ans = false;
			if ((k - h) % 2) ans = false;
		}
		else if (m % 2 == 1)
		{
			int v = n / 2;
			int rk = n * m / 2 - k;
			if (rk < v) ans = false;
			if ((rk - v) % 2) ans = false;
		}
		else
		{
			if (k % 2) ans = false;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}