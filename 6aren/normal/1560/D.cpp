#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;

    auto calc = [](int x, long long y) {
        vector<int> a, b;
        while (x) {
            a.push_back(x % 10);
            x /= 10;
        }
        while (y) {
            b.push_back(y % 10);
            y /= 10;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int cnt = 0, cur = 0;
        for (int e : b) {
            while (cur < (int) a.size() && a[cur] != e)
                cur++;
            if (cur < (int) a.size())
                cnt++, cur++;
            else break;
        }
        return (int) a.size() - cnt + (int) b.size() - cnt; 
    };

    // cout << calc(1052, 1024) << endl;

    while (tt--) {
        int x;
        cin >> x;
        int res = 1e9;
        for (int i = 0; i <= 60; i++) {
            long long foo = (1LL << i);
            res = min(res, calc(x, foo));
        }
        cout << res << '\n';
    }

    return 0;
}