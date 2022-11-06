#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];
int idx[200001];

int b[200001];

map <int, int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], idx[a[i]] = i;

	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		int sub = i - idx[b[i]];
		if (sub < 0) sub += n;
		mp[sub]++;
	}

	int ans = 0;
	for (auto it : mp) ans = max(ans, it.second);

	cout << ans;
}