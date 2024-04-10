#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

using namespace std;

// #define int long long

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*
    change null_type to int if we want to use map instead
    find_by_order(k) returns an iterator to the k-th element (0-indexed)
    order_of_key(k) returns numbers of item being strictly smaller than k
*/
template<typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ordered_set<int> os;

    int n;
    cin >> n;
    int offset = 0;
    int lastAns = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        vector<int> to_push;
        int delta = 0;
        {
            int l = 0, r = 1100000001;
            int pos = 0;
            while (r >= l) {
                int mid = (l + r) / 2;
                int val = mid + offset - os.order_of_key(mid + 1);
                if (val >= t) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (pos == 0) delta--;
            else to_push.push_back(pos);
        }
        {
            int l = 0, r = 1100000001;
            int pos = 0;
            while (r >= l) {
                int mid = (l + r) / 2;
                int val = mid + offset - os.order_of_key(mid + 1);
                if (val > t) {
                    pos = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }
            if (pos == 0) delta--;
            else to_push.push_back(pos);
        }
        for (int e : to_push) os.insert(e);
        offset += delta + 1;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int tt;
            cin >> tt;
            tt = (lastAns + tt) % 1000000001;
            lastAns = tt + offset - os.order_of_key(tt + 1);
            cout << lastAns << '\n';
        }
    }
    
    return 0;
}