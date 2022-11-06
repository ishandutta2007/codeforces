#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 2e5 + 9;

int n;
ll b[MaxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n / 2; ++i)
		cin >> b[i];

	deque<ll> dq;

	for (int i = n / 2 - 1; i >= 0; --i) {
		ll x = b[i] / 2;
		if (!dq.empty()) {
			x = min(x, dq.front());
			ll y = b[i] - x;
			if (y < dq.back()) {
				const ll diff = dq.back() - y;
				x -= diff;
			}
		}
		dq.push_front(x);
		dq.push_back(b[i] - x);
	}
	for (const ll &x : dq) {
		cout << x << ' ';
		assert(x >= 0);
	}
	return 0;
}