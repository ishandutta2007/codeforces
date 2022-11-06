#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

mt19937 rng((size_t) make_shared<char>().get());

llong d[5555][5555];

struct q_max {
    queue<llong> q;
    deque<llong> dq;

    void add(llong x) {
        q.push(x);
        while (!dq.empty() && x > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void pop() {
        if (dq.front() == q.front()) {
            dq.pop_front();
        }
        q.pop();
    }

    llong get() {
        return dq.front();
    }
};

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    for (int i = 0; i < 5555; i++) {
        for (int j = 0; j < 5555; j++) {
            d[i][j] = -1;
        }
    }

    d[0][0] = 0;

    for (int j = 1; j <= x; j++) {
        q_max q;
        for (int i = 1; i <= n; i++) {
            q.add(d[i - 1][j - 1]);
            llong mx = q.get();
//            for (int t = i - 1; t >= max(0, i - k); t--) {
//                if (d[t][j - 1] == -1) {
//                    continue;
//                }
//                mx = max(mx, d[t][j - 1]);
//            }

            if (mx != -1) {
                d[i][j] = mx + a[i - 1];
            }

            if (i - k >= 0) {
                q.pop();
            }
        }
    }

//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j <= x; j++) {
//            cout << d[i][j] << " ";
//        }
//        cout << "\n";
//    }

    llong ans = -1;
    for (int i = n; i > n - k; i--) {
        ans = max(ans, d[i][x]);
    }

    cout << ans;

    return 0;
}