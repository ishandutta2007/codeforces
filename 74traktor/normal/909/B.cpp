#include<bits/stdc++.h>

using namespace std;

set < int > R[105];
int n;

void dfs(int x) {
    for (int j = x; j <= n; ++j) {
        if ((int)R[j].size() > 0) {
            auto p = (*R[j].rbegin());
            R[j].erase(p);
            dfs(p);
            return;
        }
    }
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) R[i].insert(j);
    }
    for (int i = 0; i < n; ++i) {
        while ((int)R[i].size() > 0) {
            ans++;
            int x = (*R[i].rbegin());
            R[i].erase(x);
            dfs(x);
        }
    }
    cout << ans << '\n';
    return 0;
}