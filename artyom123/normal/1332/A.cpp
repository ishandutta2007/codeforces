#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if (x == x1 && x == x2) {
            if (a > 0 || b > 0) {
                cout << "No" << "\n";
                continue;
            }
        }
        if (y == y1 && y == y2) {
            if (c > 0 || d > 0) {
                cout << "No" << "\n";
                continue;
            }
        }
        int left = a - b;
        int right = b - a;
        int up = d - c;
        int down = c - d;
        if (left > x - x1) {
            cout << "No" << "\n";
            continue;
        }
        if (right > x2 - x) {
            cout << "No" << "\n";
            continue;
        }
        if (up > y2 - y) {
            cout << "No" << "\n";
            continue;
        }
        if (down > y - y1) {
            cout << "No" << "\n";
            continue;
        }
        cout << "Yes" << "\n";
    }
    return 0;
}