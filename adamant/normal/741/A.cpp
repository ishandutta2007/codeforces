#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int c[n];
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    int used[n];
    int ans = 1;
    memset(used, 0, sizeof(used));
    for(int i = 0; i < n; i++) {
        if(used[i]) {
            continue;
        }
        int j = i;
        vector<int> cycle;
        while(!used[j]) {
            used[j] = true;
            cycle.push_back(j);
            j = c[j];
        }
        if(j != i) {
            cout << -1 << endl;
            return 0;
        }
        int t = cycle.size();
        if(t % 2 == 0) {
            t /= 2;
        }
        ans /= __gcd(ans, t);
        ans *= t;
    }
    cout << ans << endl;
    return 0;
}