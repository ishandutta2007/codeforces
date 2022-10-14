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

void solve() {
    int r, b, g, w;
    cin >> r >> b >> g >> w;
    int ans = 0;
    ans += r % 2;
    ans += b % 2;
    ans += g % 2;
    ans += w % 2;
    if (ans <= 1) {
        cout << "Yes\n";
        return;
    }
    if (r == 0 || b == 0 || g == 0) {
        cout << "No\n";
        return;
    }
    r--; b--; g--; w += 3;
    ans = 0;
    ans += r % 2;
    ans += b % 2;
    ans += g % 2;
    ans += w % 2;
    if (ans <= 1) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}