#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 5e6 + 42;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x[2];
    cin >> n >> x[0] >> x[1];
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p[n];
    iota(p, p + n, 0);
    sort(p, p + n, [&](int x, int y) {return a[x] < a[y];});
    int mn[n][2];
    for(int i = 0; i < n; i++) {
        mn[i][0] = (x[0] + a[p[i]] - 1) / a[p[i]];
        mn[i][1] = (x[1] + a[p[i]] - 1) / a[p[i]];
    }
    bool ok[n][2], tok[n][2];
    for(int i = n - 1; i >= 0; i--) {
        for(int z = 0; z <= 1; z++) {
            ok[i][z] = mn[i][z] + i <= n;
            tok[i][z] = ok[i][z];
            if(i < n - 1) {
                tok[i][z] |= ok[i][z];
            }
            if(i + mn[i][z] < n) {
                int j = i + mn[i][z];
                if(tok[j][!z]) {
                    vector<int> ans[2];
                    for(int k = 0; k < mn[i][z]; k++) {
                        ans[z].push_back(p[i + k]);
                    }
                    while(!ok[j][!z]) {
                        j++;
                    }
                    for(int k = 0; k < mn[j][!z]; k++) {
                        ans[!z].push_back(p[j + k]);
                    }
                    
                    cout << "Yes" << endl;
                    cout << ans[0].size() << ' ' << ans[1].size() << endl;
                    for(auto it: ans[0]) {
                        cout << it + 1 << ' ';
                    }
                    cout << endl;
                    for(auto it: ans[1]) {
                        cout << it + 1 << ' ';
                    }
                    cout << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}