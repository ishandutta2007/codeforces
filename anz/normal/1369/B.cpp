#include <bits/stdc++.h>
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
		cin >> n;
		cin >> s;

		int cnt0 = 0, cnt1 = 0;

		int st = 0;
		for (; st < s.size(); st++)
		{
			if (s[st] == '0') cnt0++;
			else break;
		}

		int ed = s.size() - 1;
		for (; ed >= 0; ed--)
		{
			if (s[ed] == '1') cnt1++;
			else break;
		}

		bool flag = false;
		if (st <= ed) flag = true;

		for (int i = 0; i < cnt0; i++) cout << 0;
		if (flag) cout << 0;
		for (int i = 0; i < cnt1; i++) cout << 1;
		cout << '\n';
	}
}