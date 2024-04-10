#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int int64_t

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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


void fail() {
    cout << -1 << endl;
    exit(0);
}

int read(int x) {
    cout << x << endl;
    int t;
    cin >> t;
    if(t == 0) {
        exit(0);
    }
    return t;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    int g = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= k;
        g = __gcd(g, a[i]);
    }
    g = __gcd(g, k);
    set<int> ans;
    for(int i = 0; !ans.count(i); i = (i + g) % k) {
        ans.insert(i);
    }
    cout << ans.size() << endl;
    for(auto it: ans) {
        cout << it << ' ';
    }
    return 0;
}