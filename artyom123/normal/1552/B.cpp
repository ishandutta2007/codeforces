#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> r(n, vector<int>(5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) cin >> r[i][j];
        }
        int b = 0;
        for (int i = 1; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                if (r[b][j] < r[i][j]) cnt++;
            }
            if (cnt <= 2) b = i;
        }
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (i == b) continue;
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                if (r[b][j] < r[i][j]) cnt++;
            }
            if (cnt <= 2) ok = 0;
        }
        if (ok) cout << b + 1 << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}