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

	int t; cin >> t;
	while (t--)
	{
		int cnt[2] = { 0,0 };
		int n; cin >> n;
		for (int i = 0; i < n * 2; i++)
		{
			int a; cin >> a;
			cnt[a % 2]++;
		}

		if (cnt[0] == cnt[1]) cout << "Yes\n";
		else cout << "No\n";
	}
}