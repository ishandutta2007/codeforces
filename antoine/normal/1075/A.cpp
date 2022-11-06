#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, x, y;
	cin >> n >> x >> y;

	ll d1 = llabs(x - 1) + llabs(y - 1);
	ll d2 = llabs(x - n) + llabs(y - n);

	cout << (d1 <= d2 ? "White" : "Black");
	return 0;
}