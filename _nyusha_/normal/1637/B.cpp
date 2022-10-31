#include<bits/stdc++.h>

using namespace std;

int const maxn = 105;
int a[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int c= 0;
            for (int j = i; j <= n; ++j) {
                if (a[j] == 0) c++;
                c++;
                ans += c;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}