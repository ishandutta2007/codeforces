#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, c, sum;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c >> sum;
        c = min(c, sum);
        int x = sum / c, cnt = sum % c, cnt1 = c - cnt;
        cout << cnt1 * x * x + (x + 1) * (x + 1) * cnt << '\n';
    }
    return 0;
}