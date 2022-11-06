#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int a[1111][1111];
pair<int, int> d2[1111][1111];
pair<int, int> d5[1111][1111];
int x2[1111][1111];
int x5[1111][1111];

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int x0 = -1, y0 = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                x0 = i;
                y0 = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto& c2 = d2[i][j];
            c2 = {1e9, 1e9};
            if (i) {
                c2 = min(c2, d2[i - 1][j]);
            }
            if (j) {
                c2 = min(c2, d2[i][j - 1]);
            }
            int p2 = 0;
            if (a[i][j] == 0) {
                p2 = 1e5;
            }
            while (a[i][j] && a[i][j] % 2 == 0) {
                p2++;
                a[i][j] /= 2;
            }
            x2[i][j] = p2;
            if (c2.first == 1e9) {
                c2 = {0, 0};
            }
            c2.first += p2;

            auto& c5 = d5[i][j];
            c5 = {1e9, 1e9};
            if (i) {
                c5 = min(c5, d5[i - 1][j]);
            }
            if (j) {
                c5 = min(c5, d5[i][j - 1]);
            }
            int p5 = 0;
            if (a[i][j] == 0) {
                p5 = 1e5;
            }
            while (a[i][j] && a[i][j] % 5 == 0) {
                p5++;
                a[i][j] /= 5;
            }
            x5[i][j] = p5;
            if (c5.first == 1e9) {
                c5 = {0, 0};
            }
            c5.first += p5;
        }
    }

    auto d = d2;
    auto x = x2;
    if (d5[n - 1][n - 1].first < d2[n - 1][n - 1].first) {
        d = d5;
        x = x5;
    }

    int i = n - 1, j = n - 1;
    if (x0 != -1 && d[i][j].first > 1) {
        cout << "1\n";
        for (int i = 0; i < x0; i++) {
            cout << 'D';
        }
        for (int i = 0; i + 1 < n; i++) {
            cout << 'R';
        }
        for (int i = x0; i + 1 < n; i++) {
            cout << 'D';
        }
        return 0;
    }


    cout << d[i][j].first << "\n";
    string ans;
    while (i > 0 || j > 0) {
        if (!i || j && d[i][j - 1].first < d[i - 1][j].first) {
            ans.push_back('R');
            j--;
        } else {
            ans.push_back('D');
            i--;
        }
    }

    reverse(begin(ans), end(ans));
    cout << ans;

    return 0;
}