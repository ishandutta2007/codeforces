#include<bits/stdc++.h>

using namespace std;

int a[4], used[4];

void dfs(int v) {
    used[v] = 1;
    if (a[v] != 0) dfs(a[v]);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        used[1] = 0, used[2] = 0, used[3] = 0;
        dfs(a[0]);
        if (used[1] + used[2] + used[3] == 3) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}