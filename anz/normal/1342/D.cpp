#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;
int n, k;
int m[N];
int c[N];
int cnt[N];
int psum[N];

vector <int> ans[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> m[i];
		cnt[m[i]]++;
		psum[m[i]]++;
	}
	for (int i = 1; i <= k; i++) cin >> c[i];

	for (int i = k - 1; i >= 1; i--) psum[i] += psum[i + 1];

	int mx = 0;
	for (int i = k; i >= 1; i--)
	{
		int res = (psum[i] - 1) / c[i] + 1;
		if (res > mx)
		{
			mx = res;
		}
	}

	cout << mx << '\n';

	int idx = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < cnt[i]; j++)
		{
			ans[idx].push_back(i);
			idx = (idx + 1) % mx;
		}
	}

	for (int i = 0; i < mx; i++)
	{
		cout << ans[i].size();
		for (auto it : ans[i]) cout << ' ' << it;
		cout << '\n';
	}
}