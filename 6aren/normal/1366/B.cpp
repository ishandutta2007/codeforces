#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, x, m;
        cin >> n >> x >> m;
        int l = x, r = x;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            if (u > r || v < l) continue;
            l = min(l, u);
            r = max(r, v);
        }
        cout << r - l + 1 << '\n';
    }
    return 0;
}