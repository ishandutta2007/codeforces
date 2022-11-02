#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
int n, l, r;

void solve() {
    cin >> n >> l >> r;
    map<int, int> cl;
    for (int i = 0; i < l; i++) {
        int a;
        cin >> a;
        cl[a]++;
    }
    map<int, int> cr;
    for (int i = 0; i < r; i++) {
        int a;
        cin >> a;
        auto j = cl.find(a);
        if (j != cl.end()) {
            (*j).ss--;
            if (!(*j).ss)
                cl.erase(j);
            l--;
            r--;
            i--;
        } else {
            cr[a]++;
        }
    }
    if (l > r) {
        swap(l, r);
        cl.swap(cr);
    }
    int ans = 0;
    for (auto j = cr.begin(); j != cr.end(); j++) {
        while (r > l && (*j).ss >= 2) {
            r -= 2;
            (*j).ss -= 2;
            ans++;
        }
    }
    ans += l + (r - l);
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}