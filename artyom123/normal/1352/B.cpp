#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n % 2 == 0 && k % 2 == 1) {
            if (2 * k > n) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++) cout << 2 << " ";
            cout << n - 2 * (k - 1) << "\n";
            continue;
        }
        if (n % 2 == 0) {
            if (n < k) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++) cout << 1 << " ";
            cout << n - (k - 1) << "\n";
            continue;
        }
        if (n % 2 == 1 && k % 2 == 0) {
            cout << "NO\n";
            continue;
        }
        if (n % 2 == 1 && k % 2 == 1) {
            if (n < k) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++) cout << 1 << " ";
            cout << n - (k - 1) << "\n";
        }
    }
    return 0;
}