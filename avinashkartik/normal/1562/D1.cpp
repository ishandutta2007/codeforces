#include <bits/stdc++.h>

using namespace std;

const int N = 400005;

int n, q, p[N][4];
string s;

void solve() {
    cin >> n >> q >> s;
    s = '#' + s + '#';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) p[i][j] = p[i - 1][j];
        if (s[i] == '+') {
            if (i % 2 == 0) p[i][0]++;
            else p[i][1]++;
        } else {
            if (i % 2 == 0) p[i][2]++;
            else p[i][3]++;
        }
    }
    
    for (int no = 1; no <= q; no++) {
        int l, r; cin >> l >> r;
        l--;
        int t0 = (p[r][2] - p[l][2] + p[r][3] - p[l][3]);
        int t1 = (p[r][0] - p[l][0] + p[r][1] - p[l][1]);
        int ans = 0;
        if (t0 % 2 == 0 && t1 % 2 == 0) {
            if (p[r][0] - p[l][0] - p[r][1] + p[l][1] != 0) ans = 2;        
        } else {
            ans = (t0&1) + (t1&1);
        }
        cout << ans << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}