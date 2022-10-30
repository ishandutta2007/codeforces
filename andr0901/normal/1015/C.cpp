#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    long long s = 0;
    vector <int> diff(n);
    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        s += t1;
        diff[i] = t1 - t2;
    }
    sort(diff.rbegin(), diff.rend());
    for (int i = 0; i < n; i++) {
        if (s <= m) {
            cout << i;
            return 0;
        }
        s -= diff[i];
        //cout << s << " ";
    }
    if (s <= m) {
        cout << n;
        return 0;
    }
    cout << -1;
    return 0;
}