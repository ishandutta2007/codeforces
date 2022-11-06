#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = (int) 2e5 + 9;

struct Ch {
	ll a, b;
	ll dv;

	bool operator<(const Ch &other) const {
		return dv > other.dv;
	}

	void f() {
		dv = a / b;
	}
};

int n, k;
Ch ch[MxN + 9];

bool f(const ll x) {
	priority_queue<Ch> pq;

	for (int i = 0; i < n; ++i)
		pq.push(ch[i]);

	for (int t = 1; t < k; ++t) {
		Ch ch = pq.top();
		pq.pop();
		ch.a += x;
		ch.f();
		pq.push(ch);

		{
			const Ch &ch = pq.top();
			if (ch.a - t * ch.b < 0)
				return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> ch[i].a;
	for (int i = 0; i < n; ++i) {
		cin >> ch[i].b;
		ch[i].f();
	}

	const ll Inf = (ll) 1e13 + 9;

	ll lo = 0;
	ll hi = Inf;

	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (f(mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	cout << (lo == Inf ? -1 : lo);
	return 0;
}