//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> used(n - 1);
    vector<int> cnt(n + 1);
    int k = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            used[i] = 1;
            k++;
            cnt[arr[i]] += 2;
        }
    }
    cnt[arr[0]]++;
    cnt[arr.back()]++;
    int xx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    if (cnt[xx] > k + 1) {
        for (int i = 0; i < n - 1; i++) {
            if (used[i])
                continue;
            if (arr[i] == xx || arr[i + 1] == xx)
                continue;
            used[i] = 1;
            k++;
            if (cnt[xx] == k + 1)
                break;
        }
    }
    if (cnt[xx] > k + 1) {
        cout << -1 << endl;
        return;
    }
    cout << k - 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tests = 1;
    cin >> tests;
    while (tests--) {
        solve();
    }
}