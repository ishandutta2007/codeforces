#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct D {
	int a, b;
	bool operator<(const D &other) const {
		if ((b > 0) != (other.b > 0))
			return b > 0 && !(other.b > 0);
		return b > 0 ? a < other.a : a + b > other.a + other.b;
	}
};
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, r;
	cin >> n >> r;
	vector<D> v(n);
	for (D &d : v)
		cin >> d.a >> d.b;
	sort(v.begin(), v.end());

	for (const D &d : v) {
		//DBG(d.a)
				//DBG(d.b)
		if (r < d.a) {
			cout << "NO";
			return 0;
		}
		r += d.b;
		if (r < 0) {
			cout << "NO";
			cerr << 2;
			return 0;
		}
	}
	cout << "YES";
	return 0;
}