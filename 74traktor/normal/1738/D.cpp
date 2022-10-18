#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int a[maxn], b[maxn], in[maxn];
vector < int > g[maxn];
deque < int > ans;

void solve() {
    int n;
    cin >> n;
    ans = {};
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        g[i] = {}, in[i] = 0;
        a[i] = b[i];
    }
    sort(a + 1, a + n + 1);
    int ans_k = 0;
    for (int k = 1; k <= n; k++) {
        if (a[n - k + 1] > k && a[n - k] <= k) {
            assert(ans_k == 0);
            ans_k = k;
        }
    }
    for (int i = 1; i <= n; i++) a[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= ans_k) {
             if (b[i] != n + 1) {
                g[b[i]].push_back(i);
                in[i]++;
             } else {
                ans.push_front(i);
             }
        } else {
            if (b[i] != 0) {
                g[b[i]].push_back(i);
                in[i]++;
            } else {
                ans.push_front(i);
            }
        }
    }
    int l = 0;
    while (l < (int)ans.size()) {
        int r = ans.size();
        int what = -1;
        vector < int > add;
        for (int i = l; i < r; i++) {
            if ((int)g[ans[i]].size() > 0) {
                assert(what == -1);
                what = i;
            }
            for (auto key : g[ans[i]]) {
                in[key]--;
                if (in[key] == 0) add.push_back(key);
            }
        }
        if (what != -1) {
            while (what < (int)ans.size() - 1) {
                swap(ans[what], ans[what + 1]);
                what++;
            }
        }
        for (auto key : add) ans.push_back(key);
        l = r;
    }
    cout << ans_k << '\n';
    for (auto key : ans) cout << key << " ";
    cout << '\n';
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