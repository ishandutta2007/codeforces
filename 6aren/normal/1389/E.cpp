#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve() {
    int m, d, w;
    cin >> m >> d >> w;
    int u = min(m, d);
    int mod = w / __gcd(w, d - 1);
    int cnt1 = u % mod;
    int cnt2 = mod - u % mod;
    int dem = u / mod;
    cout << dem * (dem - 1) / 2 * cnt2 + dem * (dem + 1) / 2 * cnt1 << '\n';
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) solve();
    return 0;
}