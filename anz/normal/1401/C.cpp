#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		int mn = *min_element(a, a + n);
		vector <int> vec;
		for (int i = 0; i < n; i++)
		{
			if (a[i] % mn == 0) vec.push_back(a[i]);
		}

		sort(vec.begin(), vec.end());

		int ptr = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] % mn == 0) a[i] = vec[ptr++];
		}

		bool ans = true;
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1] > a[i]) ans = false;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}