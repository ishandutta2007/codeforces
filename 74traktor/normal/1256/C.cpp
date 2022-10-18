#include <bits/stdc++.h>
 
using namespace std;
 
int a[1005];
int ans[1005];
 
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    int pos = d, ptr = 1;
    while (ptr <= m && pos <= n) {
        pos += (a[ptr++] - 1);
        pos += d;
    }
    if (pos <= n) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    int sum = 0;
    for (int i = 1; i <= m; ++i) sum += a[i];
    int go = n - sum;
    if (go % (m + 1) == 0) {
        int f = go / (m + 1);
        ptr = 1;
        for (int i = f + 1; i <= n;) {
            for (int j = i; j < i + a[ptr]; ++j) {
                ans[j] = ptr;
            }
            i += a[ptr];
            i += f;
            ptr++;
        }
        for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
        cout << '\n';
    }
    else {
        ptr = 1;
        int f = go / (m + 1);
        int c = f + 1, cnt = go % (m + 1);
        cnt--;
        //cout << go << " " << f << " " << c << " " << cnt << '\n';
        for (int i = c + 1; i <= n;) {
            //cout << i << " OK" << '\n';
            for (int j = i; j < i + a[ptr]; ++j) ans[j] = ptr;
            i += a[ptr];
            ptr++;
            if (cnt > 0) i += c, cnt--;
            else i += f;
        }
        for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}