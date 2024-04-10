#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
int p[maxn][5];
int n;
bool ok[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < 5; e++) {
            cin >> p[i][e];
        }
    }
    int ma = 0;
    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for (int e = 0; e < 5; e++) {
            cnt += (p[ma][e] < p[i][e]);
        }
        if (cnt <= 2) {
            ma = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == ma) {
            continue;
        }
        int cnt = 0;
        for (int e = 0; e < 5; e++) {
            cnt += (p[ma][e] < p[i][e]);
        }
        if (cnt <= 2) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << ma + 1 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}