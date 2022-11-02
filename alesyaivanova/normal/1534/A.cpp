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

const int maxn = 109;
int a[maxn][maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int e = 0; e < m; e++) {
            if (s[e] == 'W') {
                a[i][e] = 0;
            } else if (s[e] == 'R')
                a[i][e] = 1;
            else {
                a[i][e] = -1;
            }
        }
    }
    bool fl = 1;
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < m; e++) {
            int x = (i + e) % 2;
            if (a[i][e] != -1 && a[i][e] != x)
                fl = 0;
        }
    }
    if (fl) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int e = 0; e < m; e++) {
                int x = (i + e) % 2;
                if (x)
                    cout << 'R';
                else
                    cout << 'W';
            }
            cout << "\n";
        }
        return;
    }
    fl = 1;
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < m; e++) {
            int x = (i + e + 1) % 2;
            if (a[i][e] != -1 && a[i][e] != x)
                fl = 0;
        }
    }
    if (fl) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int e = 0; e < m; e++) {
                int x = (i + e + 1) % 2;
                if (x)
                    cout << 'R';
                else
                    cout << 'W';
            }
            cout << "\n";
        }
        return;
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}