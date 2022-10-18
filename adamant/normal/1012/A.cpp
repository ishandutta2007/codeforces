#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
#define all(x) begin(x), end(x)

typedef double ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype dot(point a, point b) {
    return (conj(a) * b).x();
}
ftype cross(point a, point b) {
    return (conj(a) * b).y();
}

const ftype pi = acos(-1);

const int maxn = 1e6 + 42, maxt = 1e3 + 42, mod = 1e9 + 7, sigma = 26;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[2 * n];
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    sort(a, a + 2 * n);
    int ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
    for(int i = n; i < 2 * n - 1; i++) {
        ans = min(ans, (a[2 * n - 1] - a[0]) * (a[i] - a[i - (n - 1)]));
    }
    cout << ans << endl;
    return 0;
}