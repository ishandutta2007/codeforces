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

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> c(n);
    vector<int> d(n);
    vector<int> p(n);
    int s = -1;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> c[i] >> d[i];
        p[i] = i;
        if (s == -1 && x[i] == 0 && y[i] == 0) {
            s = i;
        }
    }

    sort(begin(p), end(p), [&](int i, int j) {
        return x[i] < x[j];
    });

    const int N = 1e5;
    const int B = 333;
    const int K = N / B + 1;
    vector<vector<int>> a(K);
    for (int i = 0, l = 0, r = min(n, B); l < n; i++, l = r, r = min(n, r + B)) {
        a[i].insert(begin(a[i]), begin(p) + l, begin(p) + r);
        sort(begin(a[i]), end(a[i]), [&](int i, int j) {
            return y[i] > y[j];
        });
    }

//    map<pair<int, int>, int> b;
//    b[{0, 0}] = 0;
    vector<int> par(n, -1);
    queue<tuple<int, int, int>> q;
    q.push({0, 0, -1});
    vector<int> del(n);
    while (!q.empty()) {
        auto [vx, vy, vpar] = q.front();
        q.pop();
        for (int i = 0, l = 0, r = min(B, n); l < n; i++, l = r, r = min(n, r + B)) {
            if (x[p[r - 1]] <= vx) {
                while (!a[i].empty() && y[a[i].back()] <= vy) {
                    int id = a[i].back();
                    a[i].pop_back();
                    par[id] = vpar;
                    q.push({c[id], d[id], id});
                    del[id] = 1;
                }
            } else if (x[p[l]] > vx) {
                break;
            } else {
                for (int j = l; j < r; j++) {
                    int id = p[j];
                    if (!del[id] && x[id] <= vx && y[id] <= vy) {
                        par[id] = vpar;
                        q.push({c[id], d[id], id});
                        del[id] = 1;
                    }
                }
                int t = 0;
                for (int j = 0; j < isz(a[i]); j++) {
                    if (!del[a[i][j]]) {
                        swap(a[i][j], a[i][t++]);
                    }
                }
                a[i].resize(t);
            }
        }
    }

    if (!del[n - 1]) {
        cout << "-1\n";
    } else {
        vector<int> ans;
        int c = n - 1;
        while (c != -1) {
            ans.push_back(c);
            c = par[c];
        }
        reverse(begin(ans), end(ans));
        cout << isz(ans) << "\n";
        for (auto& i : ans) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}