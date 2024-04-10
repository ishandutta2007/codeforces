#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int readInt() {
    int x;
    cin >> x;
    return x;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n = readInt();
    int g = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
        g = __gcd(a[i], g);
    }

    vector<int> pr(22222222, -1);
    for (int i = 2; i < pr.size(); i++) {
        if (pr[i] == -1) {
            for (int j = i + i; j < pr.size(); j += i) {
                pr[j] = i;
            }
        }
    }

    vector<int> cnt(22222222);
    vector<int> ws(22222222);
    int wt = 1;
    vector<int> ps(111);
    for (int i = 0; i < n; i++) {
        a[i] /= g;
        ps.clear();

        while (pr[a[i]] != -1) {
            ps.push_back(pr[a[i]]);
            a[i] /= pr[a[i]];
        }

        if (a[i] != 1) {
            ps.push_back(a[i]);
        }

        wt++;
        for (int i : ps) {
            if (ws[i] != wt) {
                cnt[i]++;
                ws[i] = wt;
            }
        }
    }


    int ans = *max_element(cnt.begin(), cnt.end());

    if (ans == 0) {
        cout << -1;
    } else {
        cout << n - ans;
    }

    return 0;
}