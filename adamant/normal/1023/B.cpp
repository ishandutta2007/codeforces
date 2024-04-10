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

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;


signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int mn = max<int>(1, k - n);
	int mx = min<int>(n, k - 1);
	int c = k / 2;
	if(mx < mn) {
		cout << 0 << endl;
	} else {
		int ans = mx - mn + 1 - (k % 2 == 0 && mn <= c && c <= mx);
		cout << ans / 2 << endl;
	}
	return 0;
}