#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == y && y == z) {
            cout << "YES\n" << x << " " << x << " " << x << "\n";
            continue;
        }
        if (x == y && x > z) {
            cout << "YES\n" << x << " " << z << " " << z << "\n";
            continue;
        }
        if (y == z && y > x) {
            cout << "YES\n" << x << " " << x << " " << y << "\n";
            continue;
        }
        if (x == z && x > y) {
            cout << "YES\n" << y << " " << x << " " << y << "\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}