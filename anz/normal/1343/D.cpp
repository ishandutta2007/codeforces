#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
ll a[200001];

int min_cnt[200001];
int max_cnt[200001];

map <ll, int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		mp.clear();

		cin >> n >> k;

		for (int i = 0; i <= k; i++) min_cnt[i] = max_cnt[i] = 0;
		for (int i = 0; i < n; i++) cin >> a[i];

		for (int i = 0; i < n / 2; i++)
		{
			min_cnt[min(a[i], a[n - 1 - i])]++;
			max_cnt[max(a[i], a[n - 1 - i])]++;

			int num = a[i] + a[n - 1 - i];
			mp[num]++;
		}

		for (int i = 1; i <= k; i++)
			max_cnt[i] += max_cnt[i - 1];

		for (int i = k - 1; i >= 0; i--)
			min_cnt[i] += min_cnt[i + 1];
		
		int ans = n / 2;
		for (auto it : mp)
		{
			int res = n / 2 - it.second;
			
			int min_num = it.first - k;

			if (min_num > 1)
				res += max_cnt[min_num - 1];

			int max_num = it.first - 1;
			
			if (max_num < k)
				res += min_cnt[max_num + 1];

			ans = min(ans, res);
		}

		cout << ans << '\n';
	}
}