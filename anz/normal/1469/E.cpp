#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k, len;
string s;

vector <int> vec;
int cache[1 << 21];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q; cin >> q;
	while (q--)
	{
		cin >> n >> k;
		cin >> s;

		int cur = 0;
		len = min(20, k);
		for (int i = k - len; i < k; i++)
		{
			cur *= 2;
			cur += s[i] - '0';
		}

		int cnt = 0;
		for (int i = 0; i < k - len; i++)
			if (s[i] == '0') cnt++;

		if (!cnt)
		{
			vec.push_back(cur);
			cache[cur]++;
		}

		for (int i = k; i < n; i++)
		{
			if (s[i - len] == '0') cnt++;
			if (s[i - k] == '0') cnt--;

			cur *= 2;
			cur += s[i] - '0';
			cur -= ((s[i - len] - '0') << len);

			if (!cnt)
			{
				vec.push_back(cur);
				cache[cur]++;
			}
		}

		int ans;
		for (ans = (1 << len) - 1; ans >= 0; ans--)
		{
			if (!cache[ans]) break;
		}

		while (!vec.empty())
		{
			int x = vec.back(); vec.pop_back();
			cache[x]--;
		}

		if (ans == -1)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		for (int i = 0; i < k - len; i++) cout << '0';
		for (int i = len - 1; i >= 0; i--) cout << 1 - !!(ans & (1 << i));
		cout << '\n';
	}
}