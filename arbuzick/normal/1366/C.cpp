#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[30][30];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> a[i][j];
        int ans = 0;
        vector<int> cnt(n+m-1), cnt2(n+m-1);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cnt[i+j] += a[i][j], cnt2[i+j] += 1-a[i][j];
        for(int i = 0; i < (n+m-1)/2; ++i)
            ans += min(cnt[i]+cnt[n+m-2-i], cnt2[i]+cnt2[n+m-2-i]);
        cout << ans << '\n';
    }
    return 0;
}