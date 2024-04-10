#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
vector < int > cnt[2 * maxn];
int inf = 1e9;
int a[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int j = 2;
        while (a[i] > 1) {
            if (j * j > a[i]) j = a[i];
            if (a[i] % j == 0) {
                int f = 0;
                while (a[i] % j == 0) a[i] /= j, f++;
                cnt[j].push_back(f);
            }
            else ++j;
        }
    }
    int ans = 1;
    for (int i = 1; i < 2 * maxn; ++i) {
        int it = 2;
        while ((int)cnt[i].size() < n && it--) cnt[i].push_back(0);
        sort(cnt[i].begin(), cnt[i].end());
        for (int j = 1; j <= cnt[i][1]; ++j) ans *= i;
    }
    cout << ans << '\n';
    return 0;
}