#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		for (char& c : s)
		{
			if (c <= 'Z') c += 'a' - 'A';
		}
		if (s == "yes") cout << "YES\n";
		else cout << "NO\n";
	}
}