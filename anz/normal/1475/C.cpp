#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int a, b, k;
int A[200001], B[200001];
int x[200001];
int y[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> a >> b >> k;

		for (int i = 1; i <= a; i++) x[i] = 0;
		for (int i = 1; i <= b; i++) y[i] = 0;

		for (int i = 0; i < k; i++)
		{
			cin >> A[i];
			x[A[i]]++;
		}

		for (int i = 0; i < k; i++)
		{
			cin >> B[i];
			y[B[i]]++;
		}

		ll ans = 0;
		for (int i = 1; i < k; i++)
		{
			int ca = A[i], cb = B[i];
			ans += (k + 1 - i) - x[ca] - y[cb] + 1;
			x[ca]--, y[cb]--;
		}

		cout << ans << '\n';
	}
}