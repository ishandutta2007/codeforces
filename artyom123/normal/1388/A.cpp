#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const int MAXN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /// 6 10 14 15
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 30) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int k = n - 30;
        if (k == 6 || k == 10 || k == 14) {
            cout << 6 << " " << 10 << " " << 15 << " " << k - 1 << "\n";
        } else {
            cout << 6 << " " << 10 << " " << 14 << " " << k << "\n";
        }
    }
    return 0;
}