#include<bits/stdc++.h>

using namespace std;

int ok[1000005];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, x, pos = 1, u, v;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> x;
        ok[x] = 1;
    }
    if (ok[1]) {
        cout << 1;
        exit(0);
    }
    for (int i = 1; i <= k; ++i) {
        cin >> u >> v;
        if (u == pos) pos = v;
        else if (v == pos) pos = u;
        if (ok[pos]) {
            cout << pos;
            exit(0);
        }
    }
    cout << pos;
    return 0;
}