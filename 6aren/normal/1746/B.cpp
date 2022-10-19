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
        vector<int> a(n + 2), pref1(n + 2), suff0(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pref1[i] = pref1[i - 1] + a[i];
        }
        for (int i = n; i >= 1; i--) {
            suff0[i] = suff0[i + 1] + (a[i] == 0);
        }
        int best = 1e9;
        for (int i = 0; i <= n; i++) {
            best = min(best, pref1[i] + suff0[i + 1] - min(pref1[i], suff0[i + 1]));
        }
        cout << best << '\n';
    }
    return 0;
}