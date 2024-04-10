//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        k[i]--;
    }
    sort(k.rbegin(), k.rend());
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    ll ans = 0;
    int mn = 0;
    for (int i = 0; i < n; i++) {
        if (k[i] > mn) {
            ans += c[mn];
            mn++;
        } else {
            ans += c[k[i]];
        }
    }
    cout << ans << endl;;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // coment next line if there is only one test
    cin >> t;

    while (t--) {
        solve();
    }
}