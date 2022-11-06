#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k, x;
ll a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	int ans = n;
	priority_queue<ll, vector<ll> ,greater<ll> > pq;
	for (int i = 1; i < n; i++)
	{
		ll res = (a[i] - a[i - 1] + x - 1) / x - 1;
		if (res > 0) pq.push(res);
		else ans--;
	}

	while (!pq.empty())
	{
		if (pq.top() > k) break;
		k -= pq.top();
		pq.pop();
		ans--;
	}

	cout << ans;
}