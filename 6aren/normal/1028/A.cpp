#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

string s[120];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    vector<ii> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'B') v.pb({i, j});
        }
    }
    ii ans = v[v.size() / 2];
    cout << ans.x << ' ' << ans.y;
    return 0;
}