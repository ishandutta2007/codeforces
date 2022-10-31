#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int a[maxn];

inline int get(int x, int mod) {
    if (x >= 0) return x % mod;
    return (mod - abs(x) % mod) % mod;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        set < int > Q;
        for (int i = 0; i < n; ++i) {
            Q.insert((i + get(a[i], n)) % n);
        }
        if ((int)Q.size() == n) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}