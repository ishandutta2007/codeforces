#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 100001;

int n;
int a[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int ans = 0;
	for (int mx = 0; mx <= 30; mx++)
	{
		bool hasVal = false;
		int curSum = 0;

		for (int i = 0; i < n; i++)
		{
			if (a[i] > mx)
			{
				hasVal = false;
				curSum = 0;
				continue;
			}

			if (a[i] == mx) hasVal = true;

			if (curSum < 0) curSum = 0;
			curSum += a[i];

			if (hasVal) ans = max(ans, curSum - mx);
		}
	}

	cout << ans;
}