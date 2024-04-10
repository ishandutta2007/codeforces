#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

namespace FFT {
    using dbl = double;

    const int N = 1 << 20;
    const dbl PI = acos(-1);

    struct num {
        dbl x, y;
        num() : x(0), y(0) {}
        num(dbl x, dbl y) : x(x), y(y) {}
        num(dbl a) : x(cos(a)), y(sin(a)) { }

        num operator + ( const num &a ) const { return num(x + a.x, y + a.y); }
        num operator - ( const num &a ) const { return num(x - a.x, y - a.y); }
        num operator * ( const num &a ) const { return num(x * a.x - y * a.y, x * a.y + y * a.x); }
    };

    num root[N];
    int rev[N];
    int n = -1, log;
    dbl n_inv;
    num na[N], nb[N], fa[N], fb[N];

    void init(int _n) {
        n = 1;
        log = 0;
        while (n < _n) {
            n <<= 1;
            log++;
        }
        assert(n <= N);
        n_inv = 1.0 / n;

        for (int i = 0; i < n; i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (log - 1));
        }

        for (int k = 1; k < n; k *= 2) {
            num tmp(PI / k);
            root[k] = {1, 0};
            for (int i = 1; i < k; i++)
                root[k + i] = (i & 1) ? root[(k + i) >> 1] * tmp : root[(k + i) >> 1]; // Way #2
        }
    }

    void fft(num* a, num* fa) {
        for (int i = 0; i < n; i++) {
            fa[rev[i]] = a[i];
        }
        for (int k = 1; k < n; k *= 2) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    num tmp = root[k + j] * fa[i + j + k];
                    fa[i + j + k] = fa[i + j] - tmp;
                    fa[i + j] = fa[i + j] + tmp;
                }
            }
        }
    }

    void fft_inv(num* fa, num* a) {
        fft(fa, a);
        reverse(a + 1, a + n);
        for (int i = 0; i < n; i++) {
            a[i].x *= n_inv;
            a[i].y *= n_inv;
        }
    }

    template <typename T>
    void get_int(num* a, vector<T>& ia) {
        for (int i = 0; i < n; i++) {
            ia[i] = (T) round(a[i].x);
        }
    }

    template <typename T>
    vector<T> mul(const vector<T>& a, const vector<T>& b) {
        init(int(a.size()) + int(b.size()));
        fill_n(na, n, num());
        fill_n(nb, n, num());
        for (int i = 0; i < int(a.size()); i++) {
            na[i].x = a[i];
        }
        for (int i = 0; i < int(b.size()); i++) {
            nb[i].x = b[i];
        }
        fft(na, fa);
        fft(nb, fb);
        for (int i = 0; i < n; i++) {
            fa[i] = fa[i] * fb[i];
        }
        fft_inv(fa, na);
        vector<T> c(n);
        get_int(na, c);
        return c;
    }
}

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    using FFT::mul;

    int n, k;
    cin >> n >> k;

    vector<int> a(1001);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    auto one = [](vector<int>& a) {
        for (int& i : a) {
            i = min(1, i);
        }
    };

    vector<int> res = {1};

    for (; k > 0; k >>= 1) {
        if (k & 1) {
            res = mul(a, res);
            one(res);
        }
        a = mul(a, a);
        one(a);
    }

    for (int i = 1; i < isz(res); i++) {
        if (res[i]) {
            cout << i << " ";
        }
    }

    return 0;
}