#include<bits/stdc++.h>

using namespace std;

int a[305][305];
int used[305];

int get(int x) {
    int i = 1, ans = 0;
    while (i < x) {
        ans += used[i++];
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector < int > go;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                used[j] = 0;
                cin >> a[i][j];
                go.push_back(a[i][j]);
            }
        }
        sort(go.begin(), go.end());
        int ans = 0;
        for (int j = 1; j <= m; ++j) {
            int pos = lower_bound(go.begin(), go.end(), a[1][j]) - go.begin() + 1;
            ans += get(pos);
            used[pos]++;
        }
        cout << ans << '\n';
    }
    return 0;
}