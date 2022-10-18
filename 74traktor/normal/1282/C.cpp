#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int f[maxn];
int s[maxn];

void solve() {
    int n, T, a, b;
    cin >> n >> T >> a >> b;
    for (int i = 1; i <= n; ++i) cin >> f[i];
    for (int i = 1; i <= n; ++i) cin >> s[i];
    vector < pair < int, int > > Q;
    for (int i = 1; i <= n; ++i) Q.push_back({s[i], f[i]});
    sort(Q.begin(), Q.end(), [](pair < int, int > s1, pair < int, int > s2) {
        if (s1.first != s2.first) return s1.first < s2.first;
        return s1.second > s2.second;
    });
    int sum = 0;
    for (auto key : Q) {
        if (key.second == 0) sum += a;
        else sum += b;
    }
    if (sum <= T) {
        cout << n << '\n';
        return;
    }
    sum = 0;
    int ans = 0, cnt_a = 0, cnt_b = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (f[i] == 0) cnt_a++;
        else cnt_b++;
    }
    int lst = -1;
    for (auto key : Q) {
        int stop = key.first - 1;
        if (key.second == 0) cnt_a--;
        else cnt_b--;
        if (sum <= stop && lst != key.first) {
            int d = (stop - sum) / a;
            d = min(d, cnt_a);
            int q = stop - sum - d * a;
            ans = max(ans, cnt + d + min(cnt_b, q / b));
        }
        lst = key.first;
        cnt++;
        if (key.second == 0) sum += a;
        else sum += b;
    }
    cout << ans << '\n';
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}