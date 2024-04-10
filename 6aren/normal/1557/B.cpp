#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &e : a) 
            cin >> e;
        vector<int> b = a;
        sort(b.begin(), b.end());
        map<pair<int, int>, bool> mp;
        for (int i = 0; i + 1 < n; i++) {
            mp[make_pair(b[i], b[i + 1])] = true;
        }
        int cnt = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (mp[make_pair(a[i], a[i + 1])] == false) cnt++;
        }

        cout << (cnt >= k ? "No\n" : "Yes\n");
    }

    return 0;
}