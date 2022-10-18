#include<bits/stdc++.h>

using namespace std;

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
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 2; i <= n; ++i) {
            while (a[i] > 0 && d >= i - 1) {
                a[i]--;
                a[1]++;
                d -= (i - 1);
            }
        }
        cout << a[1] << '\n';
    }
    return 0;
}