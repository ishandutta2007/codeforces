#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

mt19937 rng((size_t) make_shared<char>().get());

const int B = 444;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<int> l(t), r(t), id(t);
    for (int i = 0; i < t; i++) {
        cin >> l[i] >> r[i];
        --l[i]; --r[i];
        id[i] = i;
    }

    sort(begin(id), end(id), [&](int a, int b) {
        return pair(l[a] / B, r[a]) < pair(l[b] / B, r[b]);
    });

    vector<llong> cnt(1111111);
    llong ca = 0;
    vector<llong> ans(t);
    int cl = 0, cr = -1;
    for (auto& i : id) {
        while (cl < l[i]) {
            ca -= cnt[a[cl]] * cnt[a[cl]] * a[cl];
            cnt[a[cl]]--;
            ca += cnt[a[cl]] * cnt[a[cl]] * a[cl];
            ++cl;
        }
        while (cl > l[i]) {
            --cl;
            ca -= cnt[a[cl]] * cnt[a[cl]] * a[cl];
            cnt[a[cl]]++;
            ca += cnt[a[cl]] * cnt[a[cl]] * a[cl];
        }
        while (cr < r[i]) {
            ++cr;
            ca -= cnt[a[cr]] * cnt[a[cr]] * a[cr];
            cnt[a[cr]]++;
            ca += cnt[a[cr]] * cnt[a[cr]] * a[cr];
        }
        while (cr > r[i]) {
            ca -= cnt[a[cr]] * cnt[a[cr]] * a[cr];
            cnt[a[cr]]--;
            ca += cnt[a[cr]] * cnt[a[cr]] * a[cr];
            --cr;
        }
        ans[i] = ca;
    }

    for (auto& i : ans) {
        cout << i << "\n";
    }

    return 0;
}