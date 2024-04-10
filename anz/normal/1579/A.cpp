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

	int T; cin >> T;
	while (T--)
	{
		string s; cin >> s;
		int cnt[3] = { 0, };
		for (char c : s) cnt[c - 'A']++;
		if (cnt[0] + cnt[2] == cnt[1]) cout << "YES\n";
		else cout << "NO\n";
	}
}