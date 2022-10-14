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
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int ans = 0;
        int kek = min(x1, z2);
        x1 -= kek;
        z2 -= kek;
        int lol = min(z1, z2);
        z1 -= lol;
        z2 -= lol;
        ans -= 2 * z2;
        ans += 2 * min(z1, y2);
        cout << ans << "\n";
    }
    return 0;
}