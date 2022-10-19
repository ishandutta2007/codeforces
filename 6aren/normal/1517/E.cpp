#include <bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*
    change null_type to int if we want to use map instead
    find_by_order(k) returns an iterator to the k-th element (0-indexed)
    order_of_key(k) returns numbers of item being strictly smaller than k
*/
template<typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long

mt19937 rng(2911);

void solve() {


    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<int> suff(n);
    vector<int> pref(n);
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = a[i];
        if (i < n - 1) suff[i] += suff[i + 1];
    }
    for (int i = 0; i < n; i++) {
        pref[i] = a[i];
        if (i > 0) pref[i] += pref[i - 1];
    }

    ordered_set<pair<int, int>> os1, os2;

    os1.insert({0, 0});
    int of1 = 0;
    int of2 = 0;
    
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // case 1
        {
            int val = suff[i];
            if (i % 2 == 0) {
                ans += os1.order_of_key(make_pair(val - of1, 0));
            } else {
                ans += os2.order_of_key(make_pair(val - of2, 0));
            }
        }
        // if (i == 2) {
        //     cout << "-----" << endl;
        //     for (auto e : os1) {
        //         cout << e.first << ' ' << e.second << endl;
        //     }
        //     cout << os1.order_of_key(make_pair(suff[i] - of1, 0)) << endl;
        // }
        // cout << i << ' ' << ans << endl;

        if (i != n - 1) {
            int val = suff[i] - 2 * a.back();
            if (i % 2 == 0) {
                ans += os1.order_of_key(make_pair(val - of1, 0));
            } else {
                ans += os2.order_of_key(make_pair(val - of2, 0));
            }
        } 
        // cout << i << ' ' << ans << endl;
        
        int ri = suff[i];
        if (i % 2 == 0) {
            of1 -= a[i];
            of2 += a[i];
            int val1 = pref[i];
            os2.insert(make_pair(val1 - of2, ++cnt));
            if (i > 1) {
                int val2 = pref[i] - 2 * a[0];
                os2.insert(make_pair(val2 - of2, ++cnt));
            }
        } else {
            of2 -= a[i];
            of1 += a[i];
            int val1 = pref[i];
            os1.insert(make_pair(val1 - of1, ++cnt));
            if (i > 1) {
                int val2 = pref[i] - 2 * a[0];
                os1.insert(make_pair(val2 - of1, ++cnt));
            }
        }
    }

    for (int i = 0; i + 2 < n; i++) {
        if (pref[i] > suff[i + 1]) ans++;
    }

    cout << ans % 998244353 << endl;

    return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}