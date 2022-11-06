#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;
string ns;
int a[2000010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> s;
		int pre = 0;
		for (int i = 0; i < s.size() / 2; i++)
		{
			if (s[i] == s[s.size() - 1 - i]) pre++;
			else break;
		}

		string ns = s.substr(pre, s.size() - pre * 2);
		string tmp = "$";
		for (auto c : ns) tmp += c, tmp += '$';
		ns = tmp;

		for (int i = 0; i < ns.size(); i++) a[i] = 0;
		int r = -1, p = -1;
		for (int i = 0; i < ns.size(); i++)
		{
			if (i <= r) a[i] = min(a[2 * p - i], r - i);
			while (i - a[i] - 1 >= 0 && i + a[i] + 1 < ns.size() &&
				ns[i - a[i] - 1] == ns[i + a[i] + 1]) a[i]++;
			if (i + a[i] > r) r = i + a[i], p = i;
		}

		int ans = -1;
		int idx = 0;
		for (int i = 0; i < ns.size(); i++)
		{
			if (a[i] == i || a[i] == ns.size()-1-i)
			{
				if (ans < a[i])
				{
					ans = a[i];
					idx = i;
				}
			}
		}

		string res;
		for (int i = 0; i < pre; i++) res += s[i];

		for (int i = idx - ans + (ns[idx-ans]=='$'?1:0); i < idx; i+=2) res += ns[i];

		cout << res;
		if (ns[idx] != '$') cout << ns[idx];
		reverse(res.begin(), res.end());
		cout << res << '\n';
	}
}