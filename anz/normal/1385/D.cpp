#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s;

int solve(int l, int r, char c) // [l,r)
{
	if (c > 'z') return 987654321;
	if (l + 1 == r)
	{
		if (s[l] == c) return 0;
		else return 1;
	}

	int ans = 0;
	int lans = 0, rans = 0;
	for (int i = l; i < l + (r - l) / 2; i++)
	{
		if (s[i] != c) lans++;
	}
	for (int i = l + (r - l) / 2; i < r; i++)
	{
		if (s[i] != c) rans++;
	}

	ans = 987654321;
	ans = min(ans, lans + solve(l + (r - l) / 2, r, c + 1));
	ans = min(ans, solve(l, l + (r - l) / 2, c + 1) + rans);

	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> s;
		cout << solve(0, n, 'a') << '\n';
	}
}