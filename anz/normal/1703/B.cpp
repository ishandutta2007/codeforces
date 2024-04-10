#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> s;
		int a[26] = { 0, };

		int ans = s.size();
		for (char c : s)
		{
			if (a[c - 'A'] == 0)
			{
				a[c - 'A'] = 1;
				++ans;
			}
		}

		cout << ans << '\n';
	}
}