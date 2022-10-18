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
    int a[n];
    int t = sqrt(n);
    if(t * t < n) {
		t++;
	}
	vector<int> ans;
	for(int i = 0; i < t; i++) {
		for(int j = 0; j < t; j++) {
			int k = (i + 1) * t - j;
			if(k <= n) {
				ans.push_back((i + 1) * t - j);
			}
		}
	}
	for(auto it: ans) {
		cout << it << ' ';
	}
    return 0;
}