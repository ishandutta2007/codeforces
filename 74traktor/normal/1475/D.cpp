#include<bits/stdc++.h>

using namespace std;

#define int long long

int const maxn = 2e5 + 5;
int inf = 1e18;
int a[maxn], b[maxn];
vector < int > in[3];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        int sum = 0;
        for (int i = 1; i <= n; ++i) sum += a[i];
        if (sum < m) {
            cout << -1 << '\n';
            continue;
        }
        int ans = inf;
        in[1] = {}, in[2] = {};
        for (int i = 1; i <= n; ++i) in[b[i]].push_back(a[i]);
        sort(in[1].rbegin(), in[1].rend());
        sort(in[2].rbegin(), in[2].rend());
        sum = 0;
        int go = 0;
        for (auto key : in[1]) go += key;
        int ptr = (int)in[1].size() - 1;
        for (int f = 0; f <= (int)in[2].size(); ++f) {
            if (sum >= m) {
                ans = min(ans, 2 * f);
                break;
            }
            while (sum + go >= m && ptr >= 0) {
                go -= in[1][ptr];
                ptr -= 1;
            }
            if (ptr != (int)in[1].size() - 1) ans = min(ans, f * 2 + (ptr + 2));
            if (f != (int)in[2].size()) sum += in[2][f];
        }
        cout << ans << '\n';
    }
    return 0;
}