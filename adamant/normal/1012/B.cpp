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

const int maxn = 4e5 + 42, maxt = 1e3 + 42, mod = 1e9 + 7, sigma = 26;

int par[maxn];

int get(int v) {
    return v == par[v] ? v : par[v] = get(par[v]);
}

int uni(int a, int b) {
    a = get(a);
    b = get(b);
    if(a == b) {
        return 0;
    }
    par[a] = b;
    return 1;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + maxn, 0);
    int n, m, q;
    cin >> n >> m >> q;
    int r[q], c[q];
    int comps = n + m;
    for(int i = 0; i < q; i++) {
        cin >> r[i] >> c[i];
        r[i]--, c[i]--;
        comps -= uni(r[i], n + c[i]);
    }
    cout << comps - 1 << endl;
    return 0;
}