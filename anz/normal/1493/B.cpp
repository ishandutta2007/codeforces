#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int op[10] = { 0,1,5,-1,-1,2,-1,-1,8,-1 };

int h, m;

bool isValid(int ch, int cm)
{
	int a = ch / 10, b = ch % 10;
	int c = cm / 10, d = cm % 10;

	if (op[a] == -1) return false;
	if (op[b] == -1) return false;
	if (op[c] == -1) return false;
	if (op[d] == -1) return false;

	int nh = op[d] * 10 + op[c];
	int nm = op[b] * 10 + op[a];

	return h > nh && m > nm;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> h >> m;
		string s; cin >> s;

		int oh = (s[0] - '0') * 10 + s[1] - '0';
		int om = (s[3] - '0') * 10 + s[4] - '0';

		int d = 0;
		while (true)
		{
			int ch, cm;

			ch = oh;
			cm = om + d;

			ch += cm / m; cm %= m;
			ch %= h;

			if (isValid(ch, cm))
			{
				if (ch < 10) cout << 0;
				cout << ch << ":";
				if (cm < 10) cout << 0;
				cout << cm << '\n';

				break;
			}

			d++;
		}
	}
}