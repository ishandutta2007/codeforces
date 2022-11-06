#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f(const int i) {
	if (!i)
		return 0;

	ll x = (i-1)/2 + 1;
	return i&1?-x:x;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);

	int Q;
	cin >> Q;
	while (Q--) {
		int l, r;
		cin >> l >> r;
		cout << f(r) - f(l - 1) << '\n';
	}
	return 0;
}