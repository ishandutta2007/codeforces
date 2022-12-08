#include <bits/stdc++.h>

using namespace std;

const int MOD[2] = {1000000007, 1000000009};
const int BASE = 727;

struct prefix
{
	long long hash, pre;
	int len;
} a[1000005];
bool cmp(prefix a, prefix b)
{
	return (a.len > b.len);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int t = 0;
		set<long long> ss;
		while (n--)
		{
			string s;
			cin >> s;
			long long h1[2] = {0, 0}, h2[2] = {0, 0};
			for (int i = 0; i < s.size(); i++)
			{
				h1[0] = (h1[0] * BASE + s[i]) % MOD[0];
				h1[1] = (h1[1] * BASE + s[i]) % MOD[1];
				if (i >= 1)
				{
					h2[0] = (h2[0] * BASE + s[i]) % MOD[0];
					h2[1] = (h2[1] * BASE + s[i]) % MOD[1];
					a[t].pre = h2[0] * MOD[1] + h2[1];
				}
				else
					a[t].pre = -1;
				a[t].hash = h1[0] * MOD[1] + h1[1];
				ss.insert(a[t].hash);
				a[t++].len = i;
			}
		}
		sort(a, a + t, cmp);
		for (int i = 0; i < t; i++)
			if (ss.count(a[i].hash))
				ss.erase(a[i].pre);
		cout << ss.size() << "\n";
	}
	return 0;
}