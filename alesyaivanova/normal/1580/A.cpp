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

const int maxn = 409;
bool a[maxn][maxn];
int n, m;
int b1[maxn];
int b2[maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int e = 0; e < m; e++) {
            a[i][e] = (s[e] == '1');
        }
    }
    int ans = n * m + 1;
    for (int l = 0; l < n; l++) {
        for (int r = l + 4; r < n; r++) {
            if (r == l + 4) {
                for (int e = 0; e < m; e++) {
                    b1[e] = 0;
                    b2[e] = 0;
                    if (!a[l][e]) {
                        b2[e]++;
                    }
                    if (!a[r][e]) {
                        b2[e]++;
                    }
                    for (int j = l + 1; j < r; j++) {
                        if (!a[j][e]) {
                            b1[e]++;
                        }
                        if (a[j][e]) {
                            b2[e]++;
                        }
                    }
                }
            } else {
                for (int e = 0; e < m; e++) {
                    if (!a[r - 1][e]) {
                        b1[e]++;
                    }
                    if (!a[r - 1][e]) {
                        b2[e]--;
                    } else {
                        b2[e]++;
                    }
                    if (!a[r][e]) {
                        b2[e]++;
                    }
                }
            }
            int mi = 0;
            for (int e = 3; e < m; e++) {
                if (e == 3) {
                    mi = b1[0] + b2[1] + b2[2];
                } else {
                    mi = min(mi + b2[e - 1], b1[e - 3] + b2[e - 2] + b2[e - 1]);
                }
                ans = min(ans, mi + b1[e]);
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}