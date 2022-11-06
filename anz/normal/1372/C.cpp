#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];

		int r = n;
		for (; r >= 1; r--)
		{
			if (a[r] != r) break;
		}

		int l = 1;
		for (; l <= n; l++)
		{
			if (a[l] != l) break;
		}

		if (r < l)
		{
			cout << "0\n";
			continue;
		}
		
		bool flag = false;
		for (int i = l; i <= r; i++)
		{
			if (a[i] == i) flag = true;
		}

		if (flag) cout << "2\n";
		else cout << "1\n";
	}
}