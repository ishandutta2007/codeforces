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
    int n;
    cin >> n;
    vector<int> a(n);
    int xr = 0;
    for (auto &c : a) {
        cin >> c;
        xr ^= c;
    }
    if (xr == 0) {
        cout << "DRAW\n";
        return;
    }
    for (int i = 30; i >= 0; i--) {
        if (xr & (1 << i)) {
            int x = 0, y = 0;
            for (auto &c : a) {
                if (c & (1 << i)) x++;
                else y++;
            }
            if (x % 4 == 3 && y % 2 == 0) cout << "LOSE\n";
            else cout << "WIN\n";
            return;
        }
    }
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