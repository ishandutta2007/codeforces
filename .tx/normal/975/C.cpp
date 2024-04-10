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

lint a[222222];
lint s[222222];
int cur = 0;
lint acur = 0;

lint get_s(int l, int r) {
    l = max(l, cur);
    if (l > r) {
        return 0;
    }
    lint res = s[r] - (l == 0 ? 0 : s[l - 1]);
    if (l == cur) {
        res -= a[cur] - acur;
    }
    return res;
}

void solve(istream& cin, ostream& cout) {
    int n, q;
    cin >> n >> q;
    rep(i, 0, n) {
        cin >> a[i];
        s[i] = a[i];
        if (i) {
            s[i] += s[i - 1];
        }
    }
    acur = a[0];
    rep(iq, 0, q) {
        lint x;
        cin >> x;
        int l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            lint t = get_s(0, m);
            if (t <= x) {
                l = m;
            } else {
                r = m;
            }
        }
        if (l == n - 1) {
            cout << n << "\n";
            cur = 0;
            acur = a[0];
        } else {
            cout << n - 1 - l << "\n";
            x -= get_s(0, l);
            if (cur == l + 1) {
                acur -= x;
            } else {
                cur = l + 1;
                acur = a[cur] - x;
            }
        }
    }
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
}//iehjxq