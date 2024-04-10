#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    for (int j = 1; j <= t; ++j) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        set < pair < int, int > > Q;
        int ii = -1, jj = -1;
        for (int i = n; i >= 1; --i) {
            if ((int)Q.size() > 0 && (*Q.rbegin()).first >= a[i] - i) {
                ii = i, jj = (*Q.rbegin()).second;
            }
            Q.insert({a[i] - i - 1, i});
        }
        Q = {};
        for (int i = n; i >= 1; --i) {
            if ((int)Q.size() > 0 && (*Q.begin()).first <= a[i] + i) {
                ii = i, jj = (*Q.begin()).second;
            }
            Q.insert({a[i] + i + 1, i});
        }
        if (ii > jj) swap(ii, jj);
        if (ii == -1) cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
            cout << ii << " " << jj << '\n';
        }
    }
    return 0;
}