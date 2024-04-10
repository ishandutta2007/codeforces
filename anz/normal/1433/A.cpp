#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ans[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int cnt = 0;
	for (int i = 1; i <= 9; i++)
	{
		ans[i] = cnt += 1;
		ans[i * 11] = cnt += 2;
		ans[i * 111] = cnt += 3;
		ans[i * 1111] = cnt += 4;
	}

	int T; cin >> T;
	while (T--)
	{
		int x; cin >> x;
		cout << ans[x] << '\n';
	}
}