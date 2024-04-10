#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 2; i <= n; ++i) {
        if (a[i] == 0) {
            a[i] = i;
            for (int j = 2 * i; j <= n; j += i) {
                if (a[j] == 0) a[j] = i;
            }
        }
    }
    vector <int> ans;
    for (int i = 2; i <= n; ++i) {
        ans.push_back(i / a[i]);
    }
    sort(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}