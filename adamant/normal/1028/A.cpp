#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x),end(x)

const int maxn = 2e5 + 42;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = -1;
    int ax = 0, ay = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < max(n, m); k++) {
                int lx = i - k, rx = i + k;
                int ly = j - k, ry = j + k;
                if(lx >= 0 && ly >= 0 && rx < n && ry < m) {
                    if(s[lx][ly] == 'B' && s[lx][ry] == 'B' && s[rx][ly] == 'B' && s[rx][ry] == 'B' && k > ans) {
                        ans = k;
                        ax = i;
                        ay = j;
                    }
                }
            }
        }
    }
    cout << ax + 1 << ' ' << ay + 1 << endl;
    return 0;
}