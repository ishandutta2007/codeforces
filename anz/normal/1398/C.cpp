#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[100001];
int psum[100001];

map <int, int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		string s; cin >> s;

		mp.clear();
		for (int i = 1; i <= n; i++)
		{
			a[i] = s[i - 1] - '0';
			psum[i] = psum[i - 1] + a[i];
		}

		for (int i = 0; i <= n; i++)
		{
			mp[psum[i] - i]++;
		}

		ll ans = 0;
		for (auto it : mp)
		{
			ll c = it.second;
			ans += c * (c - 1) / 2;
		}

		cout << ans << '\n';
	}
}