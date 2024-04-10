#include <bits/stdc++.h>

#define int int64_t
using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[2 * n];
    vector<int> ps[n];
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        ps[a[i] - 1].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            vector<int> lol = {ps[i][0], ps[i][1], ps[j][0], ps[j][1]};
            sort(begin(lol), end(lol));
            if(a[lol[0]] != a[lol[1]]) {
                ans += 1 + (a[lol[1]] == a[lol[2]]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}