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
    string a, b;
    cin >> a >> b;
    int cnt[2][2];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) {
		cnt[a[i] == '1'][b[i] == '1']++;
	}
	int ans = 0;
	for(int a = 0; a <= 1; a++) {
		for(int b = 0; b <= 1; b++) {
			for(int c = 0; c <= 1; c++) {
				for(int d = 0; d <= 1; d++) {
					if((a | b) != (c | b) || (a | d) != (c | d)) {
						ans += cnt[a][b] * cnt[c][d];
					}
				}
			}
		}
	}
	cout << ans / 2 << endl;
    return 0;
}