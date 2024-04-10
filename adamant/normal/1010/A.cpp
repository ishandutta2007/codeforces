#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n], b[n];
    double ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) {
            fail();
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] == 1) {
            fail();
        }
    }
    double inf = 1e9;
    double l = 0, r = 1e9;
    double eps = 1e-8;
    while(r - l > eps) {
        double S = (l + r) / 2;
        double curm = S + m, curs = S;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            double x = curm / a[i];
            if(x > curs) {
                ok = false;
            } else {
                curm -= x, curs -= x;
            }
            double y = curm / b[(i + 1) % n];
            if(y > curs) {
                ok = false;
            } else {
                curm -= y, curs -= y;
            }
        }
        if(ok) {
            r = S;
        } else {
            l = S;
        }
    }
    cout << fixed << setprecision(7) << (l + r) / 2 << endl;

    return 0;
}