#include<bits/stdc++.h>

using namespace std;

#define int long long
int a[105];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int sum = 0, flag = 1;
        for (int i = 1; i <= n; ++i) {
            sum += a[i];
            if (sum < i - 1) flag = 0;
            sum -= (i - 1);
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}