#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll b[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> b[i];

	ll curMax = b[0]; cout << curMax;
	for (int i = 1; i < n; i++)
	{
		if (b[i] > 0)
		{
			curMax += b[i];
			cout << ' ' << curMax;
		}
		else
			cout << ' ' << curMax + b[i];
	}
}