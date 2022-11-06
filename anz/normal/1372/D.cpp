#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[200001];
deque <ll> psum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	ll sum = 0;

	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];

	if (n == 1)
	{
		cout << sum;
		return 0;
	}

	ll cur = 0;
	for (int i = 0; i < n / 2; i++)
	{
		psum.push_back(a[i * 2]);
		cur += a[i * 2];
	}

	ll ans = cur;

	for (int i = 0; i < n; i++)
	{
		cur -= psum.front(); psum.pop_front();
		psum.push_back(a[((n / 2 + i) * 2) % n]);
		cur += psum.back();

		ans = min(ans, cur);
	}

	cout << sum - ans;
}