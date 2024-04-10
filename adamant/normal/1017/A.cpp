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

const ftype inf = 1e16;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;


signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n], c[n], d[n];
    for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	int p[n];
	iota(p, p + n, 0);
	stable_sort(p, p + n, [&](int x, int y) {
		return a[x] + b[x] + c[x] + d[x] > a[y] + b[y] + c[y] + d[y];
	});
	for(int i = 0; i < n; i++) {
		if(p[i] == 0) {
			cout << i + 1 << endl;
		}
	}
    return 0;
}