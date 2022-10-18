#include <bits/stdc++.h>

using namespace std;

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

int sign(int x) {
    return (x > 0) - (x < 0);
}
const int maxn = 1e5 + 42;

point r[maxn];
point c, nc;

int head = -1;

point get(int v) {
    if(head == -1) {
        return r[v];
    } else {
        point oy = r[head] - c;
        oy /= abs(oy);
        return nc + point(0, 1) * (r[v] - c) / oy;
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    ftype x[n], y[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        r[i] = {x[i], y[i]};
    }
    ftype total = 0;
    for(int i = 2; i < n; i++) {
        point cur_c = (r[i] + r[i - 1] + r[0]) / (point)3;
        ftype coef = abs(cross(r[0] - r[i], r[i - 1] - r[i]));
        c += cur_c * coef;
        total += coef;
    }
    c /= total;
    int cur = 1;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int f, t;
            cin >> f >> t;
            f--, t--;
            cur ^= f;
            nc = get(cur) - point(0, abs(r[cur] - c));
            head = cur;
            cur ^= t;
        } else {
            int v;
            cin >> v;
            v--;
            point ans = get(v);
            cout << fixed << setprecision(12);
            cout << ans.x() << ' ' << ans.y() << endl;
        }
    }
    return 0;
}