#include <bits/stdc++.h>

using namespace std;

int used[150005];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    vector < int > a;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int ans = 1;
    used[max(a[0] - 1, 1)] = 1;
    for (int i = 1; i < n; ++i) {
        int x = max(1, a[i] - 1);
        if (used[x] == 0) {
            used[x] = 1;
            ans++;
        }
        else if (used[a[i]] == 0) {
            used[a[i]] = 1;
            ans++;
        }
        else {
            x = a[i] + 1;
            if (used[x] == 0) {
                used[x] = 1;
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}