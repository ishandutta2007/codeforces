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

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> s;

		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != '?') flag = true;
		}

		if (!flag) s[0] = 'R';

		for (int i = 0; i < n; i++)
		{
			if (s[i] != '?')
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (s[j + 1] == 'R') s[j] = 'B';
					else s[j] = 'R';
				}
				break;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '?')
			{
				if (s[i - 1] == 'R') s[i] = 'B';
				else s[i] = 'R';
			}
		}

		cout << s << '\n';
	}
}