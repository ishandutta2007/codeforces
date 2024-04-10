#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s, t;

set <int> st1, st2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	cin >> s >> t;

	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1') cnt0++;
		if (t[i] == '1') cnt1++;

		if (s[i] != t[i])
		{
			if (s[i] == '0') st1.insert(i);
			else st2.insert(i);
		}
	}

	if (cnt0 != cnt1)
	{
		cout << -1;
		return 0;
	}

	int ans = 0;
	while (st1.size())
	{
		ans++;

		if (*st1.begin() < *st2.begin())
		{
			auto idx = st1.begin();

			while (idx != st1.end())
			{
				int t1 = *idx;
				idx = st2.upper_bound(t1);

				if (idx == st2.end()) break;

				int t2 = *idx;
				idx = st1.upper_bound(t2);

				st1.erase(t1);
				st2.erase(t2);
			}
		}
		else
		{
			auto idx = st2.begin();

			while (idx != st2.end())
			{
				int t2 = *idx;
				idx = st1.upper_bound(t2);

				if (idx == st1.end()) break;

				int t1 = *idx;
				idx = st2.upper_bound(t1);

				st1.erase(t1);
				st2.erase(t2);
			}
		}	
	}

	cout << ans;
}