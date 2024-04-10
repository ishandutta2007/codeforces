#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (auto &e : a) cin >> e;
        long long GCD = 0;
        for (int i = 1; i < n; i++) {
            GCD = __gcd(GCD, a[i] - a[i - 1]);
            GCD = abs(GCD);
        }
        if ((k - a[0]) % GCD == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}