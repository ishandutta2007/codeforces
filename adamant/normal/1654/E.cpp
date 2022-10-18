#include <bits/stdc++.h>

#define int int64_t
#define all(x) begin(x), end(x)

using namespace std;

const int maxn = 2e5 + 42;

int cnt[maxn];
int toz[maxn];
int sz = 0;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    const int sqr = 330;
    int ans = n;
    for(int b = -sqr; b <= sqr; b++) {
        int t[n];
        for(int i = 0; i < n; i++) {
            t[i] = a[i] - b * i;
        }
        sort(t, t + n);
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(i == 0 || t[i] == t[i - 1]) {
                cur++;
            } else {
                cur = 1;
            }
            ans = min(ans, n - cur);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i; j < min<int>(n, i + sqr); j++) {
            if(i != j && abs(a[i] - a[j]) % abs(i - j) == 0) {
                int t = maxn / 2 + (a[i] - a[j]) / (i - j);
                cnt[t]++;
                toz[sz++] = t;
                ans = min(ans, n - cnt[t] - 1);
            }
        }
        while(sz) {
            cnt[toz[--sz]] = 0;
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
}