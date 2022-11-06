#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> s;
	if (s >= n * 2)
	{
		cout << "YES\n";
		for (int i = 0; i < n - 1; i++) cout << "1 ";
		cout << s - n + 1 << '\n';
		cout << n;
	}
	else cout << "NO\n";
}