#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll d, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> d >> k;

		ll a = ((ll)(double(d) / sqrt(2))) / k;
		ll b = ((ll)sqrt(d * d - a * k * a * k)) / k;

		if ((a + b) % 2) cout << "Ashish\n";
		else cout << "Utkarsh\n";
	}
}