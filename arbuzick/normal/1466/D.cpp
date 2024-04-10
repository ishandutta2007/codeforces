#include <bits/stdc++.h>
using namespace std;

#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
//#define _USE_MATH_DEFINES
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> cnt(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cnt[a]++, cnt[b]++;
    }
    multiset<pair<int, int>> s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i];
        if (cnt[i] > 1)
            s.insert({a[i], cnt[i]-1});
    }
    for (int i = 0; i < n-1; ++i) {
        cout << ans << ' ';
        if (s.size()) {
            ans += s.rbegin()->f;
            pii x = *s.rbegin();
            s.erase(s.find(x));
            if (x.s > 1) {
                s.insert({x.f, x.s-1});
            }
        }
    }
    cout << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}