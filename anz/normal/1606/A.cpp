#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> s;
		if (s.front() == s.back())
		{
			cout << s << '\n';
			continue;
		}

		if (s[0] == 'a') s[0] = 'b';
		else s[0] = 'a';

		cout << s << '\n';
	}
}