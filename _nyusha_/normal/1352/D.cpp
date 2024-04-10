#include<bits/stdc++.h>

using namespace std;

int a[1005];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int s1 = 0, s2 = 0, l = 1, r = n, cnt = 0, lst1 = 0, lst2 = 0;
        while (l <= r) {
            cnt++;
            int f = 0;
            if (cnt % 2 == 1) {
                while (l <= r && f <= lst2) {
                    f += a[l], s1 += a[l++];
                }
                lst1 = f;
            }
            else {
                while (r >= l && f <= lst1) {
                    f += a[r];
                    s2 += a[r--];
                }
                lst2 = f;
            }
        }
        cout << cnt << " " << s1 << " " << s2 << '\n';
    }
    return 0;
}