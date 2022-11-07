#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;
int psum[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			psum[i + 1] = psum[i];
			if (s[i] == '(' || s[i] == ')') continue;
			if (i % 2) psum[i + 1]++;
			else psum[i + 1]--;
		}

		int q; cin >> q;
		while (q--)
		{
			int l, r; cin >> l >> r;
			int val = psum[r] - psum[l - 1];

			//cout << "ANS: ";
			cout << abs(val) << '\n';
		}
	}
}