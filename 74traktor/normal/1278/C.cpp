#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int inf = 1e18;
unordered_map < int, int > get_ans;
int a[maxn];

void solve() {
    get_ans.clear();
    int n, ans = inf, cnt1 = 0, cnt2 = 0;
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) cin >> a[i];
    get_ans[0] = 2 * n + 1;
    for (int i = 2 * n; i >= n + 1; --i) {
        if (a[i] == 1) cnt1++;
        else cnt2++;
        get_ans[cnt1 - cnt2] = i;
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i <= n; ++i) {
        if (i != 0) {
            if (a[i] == 1) cnt1++;
            else cnt2++;
        }
        if (get_ans.find(cnt2 - cnt1) != get_ans.end()) ans = min(ans, n - i + get_ans[cnt2 - cnt1] - n - 1);
    }
    cout << ans << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}