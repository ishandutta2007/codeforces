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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << 9;
        if (n > 1) {
             cout << 8;
        }
        if (n > 2) {
            cout << 9;
        }
        for (int i = 3; i < n; ++i) {
            cout << ((i-3)%10);
        }
        cout << '\n';
    }
    return 0;
}