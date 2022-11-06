#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

const int M = int(1e9) + 7;

void add(int &a, int b) {
    a += b;
    if (a >= M) {
        a -= M;
    }
}

int d[5555][5555];

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<char> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = s[0];
    }

    d[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        bool pf = (i > 1 && a[i - 2] == 'f');
        int x = 0;
        for (int j = n; j >= 0; j--) {
            add(x, d[i - 1][j]);
            if (pf) {
                if (j) {
                    d[i][j] = d[i - 1][j - 1];
                }
            } else {
                d[i][j] = x;
            }
        }
    }

//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= n; j++) {
//            cout << d[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << endl;

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        add(ans, d[n][i]);
    }

    cout << ans;


    return 0;
}//eehyvw