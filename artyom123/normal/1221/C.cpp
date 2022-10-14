#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int c, m, x;
        cin >> c >> m >> x;
        int left = 0, right = min(c, m) + 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (x + c + m - 2 * mid >= mid) left = mid;
            else right = mid;
        }
        cout << left << "\n";
    }
    return 0;
}