#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, a, b; cin >> n >> a >> b;
	for(ll i = 0; i <= 10000000; i++)
		if(n >= a * i && (n - a * i) % b == 0)
			return cout << "YES" << endl << i << ' ' << (n - a * i) / b, 0;
	cout << "NO";
}