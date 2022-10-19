#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n >= 100) {
        cout << 1;
        return 0;
    }
    vector<int> pr(n+1);
    for (int i = 0; i < n; ++i)
        pr[i+1] = pr[i]^a[i];
    int ans = -1;
    for (int i = 0; i+1 < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j; k < n; ++k) {
                if ((pr[j]^pr[i]) > (pr[k+1]^pr[j])) {
                    if (ans == -1 || k-i-1 < ans) {
                        ans = k-i-1;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}