#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		int i = 1;
		for (; i < n; i++)
		{
			if (a[i - 1] > a[i]) break;
		}

		for (; i < n; i++)
		{
			if (a[i - 1] < a[i]) break;
		}

		bool ans = true;
		if (i != n) ans = false;

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}