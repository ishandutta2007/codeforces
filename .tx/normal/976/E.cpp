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

void solve(istream& cin, ostream& cout) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, int>> p(n);
    rep(i, 0, n) {
        cin >> p[i].first >> p[i].second;
    }
    lint s = 0;
    rep(i, 0, n) {
        s += p[i].second;
    }
    if (b == 0) {
        cout << s;
        return;
    }
    lint add = 0;
    lint ans = s;
    sort(p.begin(), p.end(), [](auto x, auto y) { return x.first - x.second > y.first - y.second;});
    b = min(b, n);
    int u = b;
    rep(i, 0, b) {
        if (p[i].first <= p[i].second) {
            u = i;
            break;
        }
        add += p[i].first - p[i].second;
    }
    ans += add;
    rep(i, 0, n) {
        lint oadd = add;
        if (i < u) {
            add -= p[i].first - p[i].second;
        } else if (u > 0 && u == b) {
            add -= p[u - 1].first - p[u - 1].second;
        }
        add += max(0, (1LL << a) * p[i].first - p[i].second);
        ans = max(ans, s + add);
        add = oadd;
    }

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
}//pzqfhk