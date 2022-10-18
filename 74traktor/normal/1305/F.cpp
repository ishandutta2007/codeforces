#include<bits/stdc++.h>

using namespace std;

#define int long long

int const maxn = 2e5 + 5;
int a[maxn];
int ans;
set < int > was;

inline void solve(int x, int n) {
    if (was.find(x) != was.end()) return;
    was.insert(x);
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        int f = a[i] % x;
        if (a[i] < x) cur += (x - a[i]);
        else cur += min(f, x - f);
        if (cur > ans) return;
    }
    ans = min(ans, cur);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector < int > Q;
    for (int i = 1; i <= n; ++i) Q.push_back(i);
    random_shuffle(Q.begin(), Q.end());
    random_shuffle(Q.begin(), Q.end());
    random_shuffle(Q.begin(), Q.end());
    for (auto key : Q) {
        for (int j = -1; j <= 1; ++j) {
            int x = a[key] + j;
            int i = 2;
            while (i * i <= x) {
                if (x % i == 0) {
                    while (x % i == 0) x /= i;
                    solve(i, n);
                    if (1.0 * clock() / CLOCKS_PER_SEC > 2.35) {
                        cout << ans << '\n';
                        exit(0);
                    }
                }
                ++i;
            }
            if (x > 1) solve(x, n);
        }
    }
    cout << ans << '\n';
    return 0;
}