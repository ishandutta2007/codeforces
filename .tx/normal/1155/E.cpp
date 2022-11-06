#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
mt19937 rng((size_t) make_shared<char>().get());

const int M = int(1e6) + 3;

void mul(int& a, int b) {
    a = 1LL * a * b % M;
}

void add(int& a, int b) {
    a = (a + b) % M;
}

vector<int> A = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};

int ask(int x) {
#ifdef VSE
    int c = 1;
    int r = 0;
    for (int i = 0; i < 11; i++) {
        add(r, 1LL * c * A[i] % M);
        mul(c, x);
    }
    return r;
#else
    cout << "? " << x << endl;
    int r;
    cin >> r;
    return r;
#endif
}

int mpow(int a, int p) {
    int res = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            mul(res, a);
        }
        mul(a, a);
    }
    return res;
}

int main(int argc, char** argv) {
#ifdef VSE
    // if (argc > 1) assert(freopen(argv[1], "r", stdin));
    rng.seed(0);
#endif
#ifndef cin
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif

    int n = 11;
    vector<vector<int>> a(n, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        int c = 1;
        for (int j = 0; j < n; j++) {
            a[i][j] = c;
            c = c * i % M;
        }
        a[i][n] = ask(i);
    }

    int c = 0;
    vector<int> p(n);
    iota(begin(p), end(p), 0);
    
    for (int i = 0; i < n; i++) {
        int x = -1;
        for (int j = c; j < n; j++) {
            if (a[j][i]) {
                x = j;
                break;
            }
        }
        if (x == -1) {
            continue;
        }
        swap(a[c], a[x]);
        
        int z = mpow(a[c][i], M - 2);
        for (int j = i; j <= n; j++) {
            mul(a[c][j], z);
        }

        for (int j = c + 1; j < n; j++) {
            int z = -a[j][i];
            for (int k = i; k <= n; k++) {
                add(a[j][k], 1LL * z * a[c][k] % M);
            }
        }

        c++;
    }

    vector<int> aa(n);
    for (int i = c - 1; i >= 0; i--) {
        int x = -1;
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                x = j;
                break;
            }
        }
        aa[x] = a[i][n];
        for (int j = x + 1; j < n; j++) {
            add(aa[x], -1LL * a[i][j] * aa[j] % M);
        }
    }

    for (int i = 0; i < M; i++) {
        int c = 1;
        int x = 0;
        for (int j = 0; j < n; j++) {
            add(x, 1LL * c * aa[j] % M);
            mul(c, i);
        }

        if (x == 0) {
            assert(ask(i) == 0);
            cout << "! " << i << endl;
            return 0;
        }
    }

    cout << "! -1" << endl;

    return 0;
}