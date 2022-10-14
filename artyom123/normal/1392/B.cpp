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
        int n;
        cin >> n;
        ll k;
        cin >> k;
        vector<int> a(n);
        int mx = -INF, mn = INF;
        for (auto &c : a) {
            cin >> c;
            mx = max(mx, c); mn = min(mn, c);
        }
        if (k % 2 == 0) {
            for (auto &c : a) cout << c - mn << " ";
        } else {
            for (auto &c : a) cout << mx - c << " ";
        }
        cout << "\n";
    }
    return 0;
}