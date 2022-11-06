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
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++) cout << '(';
			for (int j = 0; j <= i; j++) cout << ')';
			for (int j = 0; j < n - i - 1; j++) cout << "()";
			cout << '\n';
		}
	}
}