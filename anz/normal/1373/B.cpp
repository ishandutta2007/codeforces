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
		string s; cin >> s;
		int cnt[2] = { 0,0 };
		for (char c : s) cnt[c - '0']++;
		int res = min(cnt[0], cnt[1]);
		if (res % 2) cout << "DA\n";
		else cout << "NET\n";
	}
}