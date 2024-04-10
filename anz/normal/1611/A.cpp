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

		bool flag = false;
		for (char c : s)
		{
			if ((c - '0') % 2 == 0) flag = true;
		}

		if ((s.back() - '0') % 2 == 0) cout << "0\n";
		else if ((s.front() - '0') % 2 == 0) cout << "1\n";
		else if (flag) cout << "2\n";
		else cout << "-1\n";
	}
}