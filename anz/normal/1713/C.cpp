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

		int i = n - 1;
		while (i >= 0)
		{
			int x = 0;
			while (x * x < i) ++x;

			int l = i;
			while (true)
			{
				if (x * x - i > l) break;
				a[i] = x * x - i;
				--i;
			}
		}

		for (int i = 0; i < n; i++) cout << a[i] << ' ';

		cout << '\n';
	}
}