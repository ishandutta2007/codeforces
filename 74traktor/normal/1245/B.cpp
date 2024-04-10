#include <bits/stdc++.h>

using namespace std;

char ans[105];
int used[105];

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) used[i] = 0;
    int a1 = 0, b1 = 0, c1 = 0;
    for (auto c : s) {
        if (c == 'R') a1++;
        else if (c == 'P') b1++;
        else c1++;
    }
    int x = min(a, c1) + min(b, a1) + min(c, b1);
    if (x >= (n + 1) / 2) {
        cout << "YES" << '\n';
        int ptr = 0;
        for (auto d : s) {
            if (d == 'R' && b > 0) b--, ans[ptr] = 'P';
            else if (d == 'P' && c > 0) c--, ans[ptr] = 'S';
            else if (d == 'S' && a > 0) a--, ans[ptr] = 'R';
            else used[ptr] = 1;
            ptr++;
        }
        for (int i = 0; i < n; ++i) {
            if (used[i] == 1) {
                if (a > 0) a--, ans[i] = 'R';
                else if (b > 0) b--, ans[i] = 'P';
                else if (c > 0) c--, ans[i] = 'S';
            }
        }
        for (int i = 0; i < n; ++i) cout << ans[i];
        cout << '\n';
    }
    else cout << "NO" << '\n';
}

main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}