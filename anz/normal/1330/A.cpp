#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, x;
bool isExist[301];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(isExist, 0, sizeof isExist);
		cin >> n >> x;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			isExist[a] = 1;
		}

		int ans = 0;
		while (true)
		{
			if (!isExist[ans + 1])
			{
				if (x) x--;
				else break;
			}
			ans++;
		}

		cout << ans << '\n';
	}
}