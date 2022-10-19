//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

int calc(int x) {
    int cur = 2;
    int ans = 1;

    while (cur * cur <= x) {
        if (x % cur == 0) {
            int cnt = 0;
            while (x % cur == 0) {
                cnt++;
                x /= cur;
            }
            if (cnt % 2 == 1) {
                ans *= cur;
            }
        }
        cur++;
    }
    ans *= x;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = calc(a[i]);
        cnt[a[i]]++;
    }
    int max_odd = 1;
    int max_even = 0;
    int sum_even = 0;
    if (cnt[1] % 2 == 1) {
        sum_even += cnt[1];
    }
    for (auto &el : cnt) {
        if (el.second % 2 == 0) {
            max_even = max(max_even, el.second);
            sum_even += el.second;
        } else {
            max_odd = max(max_odd, el.second);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        ll w;
        cin >> w;
        if (w == 0) {
            cout << max(max_odd, max_even);
        } else {
            cout << max(max_odd, sum_even);
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // coment next line if there is only one test
    cin >> t;

    while (t--) {
        solve();
    }
}