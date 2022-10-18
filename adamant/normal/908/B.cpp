#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)

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
    int p[4] = {0, 1, 2, 3};
    string t;
    cin >> t;
    int ans = 0;
    do {
        int sx, sy;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i][j] == 'S') {
                    sx = i, sy = j;
                }
            }
        }
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for(auto c: t) {
            c -= '0';
            sx += dx[p[c]];
            sy += dy[p[c]];
            if(sx < 0 || sx >= n || sy < 0 || sy >= m || s[sx][sy] == '#') {
                goto nxt;
            } else if(s[sx][sy] == 'E') {
                ans++;
                goto nxt;
            }
        }
        ans += s[sx][sy] == 'E';
        nxt:;
    } while(next_permutation(p, p + 4));
    cout << ans << endl;
    return 0;
}