#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int a[maxn], b[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k == n - 1 && n == 4) {
            cout << -1 << '\n';
            continue;
        }
        if (k == n - 1) {
            vector < pair < int, int > > ans;
            ans.push_back({k, k - 1});
            ans.push_back({1, 3});
            ans.push_back({(n - 1)^3, 0});
            for (int i = 0; i < n; ++i) {
                int a = i, b = (n - 1)^i;
                if (a == 0 || a == k || a == k - 1 || a == ((n - 1)^3) || a == 1 || a == 3) continue;
                if (a < b) ans.push_back({a, b});
            }
            int s = 0;
            for (auto key : ans) {
                cout << key.first << " " << key.second << '\n';
                s += (key.first&key.second);
            }
            assert(s == k);
            continue;
        }
        vector < pair < int, int > > ans = {{k, n - 1}};
        if (k != 0) ans.push_back({(n - 1)^k, 0});
        for (int i = 0; i < n; ++i) {
            int a = i, b = (n - 1)^i;
            if (a == 0 || a == k || a == n - 1 || a == ((n - 1)^k)) continue;
            if (a < b) ans.push_back({a, b});
        }
        int s = 0;
        for (auto key : ans) {
            cout << key.first << " " << key.second << '\n';
                s += (key.first&key.second);
        }
        assert(s == k);
    }
    return 0;
}