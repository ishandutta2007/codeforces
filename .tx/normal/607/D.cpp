#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    const int N = 2e5;
    const int B = 555;
    const int K = N / B + 1;

    vector<int> a(N);
    int q;
    cin >> a[0] >> q;
    vector<tuple<int, int, int>> qs(q);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        int x, y;
        if (t == 1) {
            cin >> x >> y;
            --x;
            qs[i] = {t, x, y};
        } else {
            cin >> x;
            --x;
            qs[i] = {t, x, -1};
        }
    }

    const int M = int(1e9) + 7;

    vector<int> par(N, -1);
    vector<pair<int, llong>> cpar(N);
    vector<int> ask(N);
    vector<vector<pair<int, llong>>> cg(N);
    vector<vector<int>> g(N);
    vector<llong> val(N);
    int n = 1;

    auto add = [](llong& a, llong b) { a = (a + b) % M; };
    auto mul = [](llong& a, llong b) { a = a * b % M; };

    vector<int> inv(N + 1);
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = (M - inv[M % i]) * 1LL * (M / i) % M;
    }

    function<void(int, int, int, llong)> dfs = [&](int v, int p, int lp, llong pp) {
        int c = isz(g[v]) + 1;
        if (ask[v]) {
            cpar[v] = {lp, pp};
            lp = v;
            pp = 1;
        } else {
            mul(pp, c);
        }
        val[v] = a[v];
        for (int i : g[v]) {
            if (i == p) {
                continue;
            }
            dfs(i, v, lp, pp);
            add(val[v], val[i]);
        }
        mul(val[v], llong(c));
    };

    for (int l = 0, r = min(q, B); l < q; l = r, r = min(q, r + B)) {
        for (int i = 0; i < N; i++) {
            ask[i] = 0;
            cg[i].clear();
            cpar[i] = {-1, 0};
        }
        int cn = n;
        for (int iq = l; iq < r; iq++) {
            auto [t, x, y] = qs[iq];
            ask[x] = 1;
        }
        dfs(0, -1, -1, 1);

        for (int iq = l; iq < r; iq++) {
            auto [t, x, y] = qs[iq];
            if (t == 1) {
                llong old = val[x];
                llong sum = val[x];
                mul(sum, inv[isz(g[x]) + 1]);
                add(sum, y);

                g[x].push_back(n);
                cpar[n] = {x, 1};
                val[n] = y;
                a[n] = y;

                val[x] = sum;
                mul(val[x], isz(g[x]) + 1);

                auto [z, pp] = cpar[x];
                llong op = pp;
//                mul(pp, isz(g[x]) + 1);
//                mul(op, isz(g[x]));

                while (z != -1) {
                    mul(pp, isz(g[z]) + 1);
                    mul(op, isz(g[z]) + 1);
                    add(val[z], val[x] * pp - old * op);
                    mul(pp, cpar[z].second);
                    mul(op, cpar[z].second);
                    z = cpar[z].first;
                }

                n++;
            } else {
                if (val[x] < 0) {
                    val[x] += M;
                }
                cout << val[x] << "\n";
            }
        }
    }

    return 0;
}