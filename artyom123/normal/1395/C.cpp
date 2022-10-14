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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    vector<int> usd(9);
    for (int i = 8; i >= 0; i--) {
        bool can = true;
        for (auto &c : a) {
            bool f = false;
            for (auto &l : b) {
                int res = (c & l);
                bool now = true;
                for (int j = 8; j >= i; j--) {
                    if (!usd[j] && (res & (1 << j))) now = false;
                }
                if (now) f = true;
            }
            if (!f) can = false;
        }
        if (!can) usd[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        if (usd[i]) ans |= (1 << i);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}