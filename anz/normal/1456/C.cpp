#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
ll c[500001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> c[i];
	sort(c, c + n);
	reverse(c, c + n);

	priority_queue<ll> pq;
	for (int i = 0; i < k + 1; i++) pq.push(0);

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll cur = pq.top(); pq.pop();
		ans += cur;
		pq.push(cur + c[i]);
	}

	cout << ans;
}