#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
#define all(x) begin(x), end(x)

typedef int ftype;
typedef complex<ftype> point;
#define x real
#define y imag

point cmul(point a, point b) {
	return conj(a) * b;
}
ftype dot(point a, point b) {
	return cmul(a, b).x();
}
ftype cross(point a, point b) {
	return cmul(a, b).y();
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int b[n];
	copy(a, a + n, b);
	set<pair<int, int>> lol;
	for(int i = 0;  i < n; i++) {
		lol.insert({a[i], i});
	}
	for(int i = 0; i < n; i++) {
		auto it = lol.lower_bound({a[i] + 1, 0});
		if(it == end(lol)) {
			it = begin(lol);
		}
		b[i] = it->first;
		lol.erase(it);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		cnt += b[i] > a[i];
	}
	cout << cnt << endl;
	return 0;
}