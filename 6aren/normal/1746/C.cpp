#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include<cp/debugger.hpp>
#else 
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            res[a[i]] = (i == n ? 1 : i + 1);
        }
        for (int i = 1; i <= n; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}