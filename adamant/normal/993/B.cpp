#include <bits/stdc++.h>

#define int int64_t
using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n][2], b[m][2];
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        sort(a[i], a[i] + 2);
    }
    for(int j = 0; j < m; j++) {
        cin >> b[j][0] >> b[j][1];
        sort(b[j], b[j] + 2);
    }
    set<int> nma[n], nmb[m];
    set<int> nums;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][0] == b[j][0] && a[i][1] != b[j][1] ||
               a[i][0] == b[j][1] && a[i][1] != b[j][0] ||
               a[i][1] == b[j][0] && a[i][0] != b[j][1] ||
               a[i][1] == b[j][1] && a[i][0] != b[j][0]) {
                   int num;
                   if(a[i][0] == b[j][0] || a[i][0] == b[j][1]) {
                       num = a[i][0];
                   } else {
                       num = a[i][1];
                   }
                   nma[i].insert(num);
                   nmb[j].insert(num);
                   nums.insert(num);
               }
        }
    }
    if(nums.size() == 1) {
        cout << *nums.begin() << endl;
    } else {
        bool ok = true;
        for(int i = 0; i < n; i++) {
            ok &= nma[i].size() <= 1;
        }
        for(int i = 0; i < m; i++) {
            ok &= nmb[i].size() <= 1;
        }
        if(ok) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}