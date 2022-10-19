#include <bits/stdc++.h>

#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int kek = sqrt(n * 2 - 1);
    cout << (kek - 1) / 2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}