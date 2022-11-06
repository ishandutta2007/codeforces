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
		int n; cin >> n;
		string s; cin >> s;
		int cnt[2] = { 0,0 };
		for (char c : s) cnt[c - '0']++;

		vector <int> ans;
		for (int i = 0; i < n; i++)
		{
			if (i < cnt[0] && s[i] == '1') ans.push_back(i);
			if (i >= cnt[0] && s[i] == '0') ans.push_back(i);
		}

		if (ans.empty())
		{
			cout << "0\n";
			continue;
		}

		cout << "1\n";
		cout << ans.size() << ' ';
		for (int k : ans) cout << k + 1 << ' ';
		cout << '\n';
	}
}