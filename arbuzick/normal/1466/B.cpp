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
    vector<int> a(n), cnt(n*2+2), cnt2(n*2+2);
    for (int i = 0; i < n; ++i)
        cin >> a[i], cnt[a[i]]++;;
    int ans = 0;
    for (int i = 0; i < cnt.size(); ++i) {
        if (i == cnt.size()-1) {
            if (cnt[i]+cnt2[i])
                ans++;
        } else {
            if (cnt[i]+cnt2[i])
                ans++;
            if (cnt[i] > 0 && cnt[i]+cnt2[i] > 1)
                cnt2[i+1]++;
        }
    }
    cout << ans << '\n';
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