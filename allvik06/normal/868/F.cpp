#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll INF = 1e14;
vector<int> a;
vector<ll> dp, dp1;
vector<int> cnt;
ll cur = 0;

inline void add(int x) {
    cur += cnt[x];
    ++cnt[x];
}

inline void del(int x) {
    --cnt[x];
    cur -= cnt[x];
}

int curl = 0, curr;

void calc(int l, int r, int optl, int optr) {
    if (l > r) return;
    int m = (l + r) / 2;
    int tmp = optr;
    tmp = min(tmp, m);
    while (curl > tmp + 1) {
        curl--;
        add(a[curl]);
    }
    while (curl < tmp + 1) {
        del(a[curl]);
        ++curl;
    }
    while (curr < m) {
        ++curr;
        add(a[curr]);
    }
    while (curr > m) {
        del(a[curr]);
        --curr;
    }
    int ans = -1;
    for (int i = tmp; i >= optl; --i) {
        add(a[i]);
        if (dp1[m] > dp[i - 1] + cur) {
            dp1[m] = dp[i - 1] + cur;
            ans = i;
        }
        curl--;
    }
    calc(l, m - 1, optl, ans);
    calc(m + 1, r, ans, optr);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    dp.resize(n);
    dp1.resize(n, INF);
    cnt.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        add(a[i]);
        dp[i] = cur;
    }
    curr = n - 1;
    for (int i = 2; i <= k; ++i) {
        calc(i - 1, n - 1, i - 1, n - 1);
        dp.swap(dp1);
        dp1.assign(n, INF);
    }
    cout << dp.back();
}