#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		ll a, b, k;
		cin >> a >> b >> k;

		cout << a*((k+1)/2) - b*(k/2) << '\n';
	}
	return 0;
}