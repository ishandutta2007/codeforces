#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f first
#define s second

signed main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        if (l >= (r + 2) / 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}