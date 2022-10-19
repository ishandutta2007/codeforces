#include <bits/stdc++.h>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int n, m, q;
    cin >> n >> m;
    int ans = 0;
    vector <int> now(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        if (x > y) swap(x, y);
        if (now[x] == 0) ++ans;
        now[x]++;
    }
    cin >> q;
    while (q--) {
        int type, x, y;
        cin >> type;
        if (type == 1) {
            cin >> x >> y; --x; --y;
            if (x > y) swap(x, y);
            if (now[x] == 0) ++ans;
            now[x]++;
        } else if (type == 2){
            cin >> x >> y; --x; --y;
            if (x > y) swap(x, y);
            --now[x];
            if (now[x] == 0) --ans;
        } else {
            cout << n - ans << "\n";
        }
    }
}