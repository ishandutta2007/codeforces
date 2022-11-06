#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct S {
	ll a, b;

	ll f(const S &other) const {
		return b + other.a;
	}

	bool operator<(const S &other) const {
		return this->f(other) < other.f(*this);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<S> v(n);
	for (S &s : v)
		cin >> s.a >> s.b;

	sort(v.begin(), v.end());

	ll res = 0;

	for (int i = 0, j = 1; i < n; ++i, ++j)
		res += v[i].a * (j - 1) + v[i].b * (n - j);
	cout << res;
	return 0;
}