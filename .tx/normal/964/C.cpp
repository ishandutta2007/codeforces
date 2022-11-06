#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define STRESS 0

const int M = (int) 1e9 + 9;

int mpow(int a, int p) {
    int res = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            res = 1LL * res * a % M;
        }
        a = 1LL * a * a % M;
    }
    return res;
}

void mul(int& a, int b) {
    a = 1LL * a * b % M;
}

void add(int& a, int b) {
    a = (0LL + a + b + M) % M;
}

void solve(istream& cin, ostream& cout) {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;

    int o = 0;
    rep(i, 0, k) {
        int x = 1LL * mpow(a, n - i) * mpow(b, i) % M;
        if (s[i] == '+') {
            add(o, x);
        } else {
            add(o, -x);
        }
    }

    int an = mpow(a, M - 2);

    int q = 1LL * mpow(an, k) * mpow(b, k) % M;
    if (q == 1) {
        int ans = 1LL * o * (n + 1) / k % M;
        cout << ans;
        return;
    }

    int qn = mpow(q, (n + 1) / k);
    int x = 1LL * (1 - qn + M) % M * mpow((1 - q + M) % M, M - 2) % M;

    int ans = 1LL * o * x % M;

    cout << ans;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//xqveiv