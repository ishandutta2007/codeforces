#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> d(n);
        for (int &e : d) cin >> e;
        sort(d.begin(), d.end());
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += 1LL * (i + 1) * d[i] - 1LL * (n - i) * d[i];
        }
        cout << -res + d.back() << '\n'; 
    }

    return 0;
}