#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x) {
	return (x / 2) * (x / 2) + (x & 1 ? x / 2 : 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

ll x;
cin >> x;

ll ans = 0;
while(f(ans) < x)
	++ans;
cout << ans;
	return 0;
}