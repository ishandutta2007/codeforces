#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int k; cin >> k;
	cout << "3 3\n";
	cout << "262143 262143 262143\n";
	cout << "131072 " << k << " 131072\n";
	cout << "262143 262143 131071\n";
}