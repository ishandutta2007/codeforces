#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n;
	cin >> n;

	set<ll> s;

	while (!s.count(n)) {
		s.insert(n);
		n++;
		for (int rep = 0; rep < 100 && n % 10 == 0; ++rep)
			n /= 10;
	}

	cout << s.size();
	return 0;
}