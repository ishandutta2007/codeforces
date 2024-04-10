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

const int maxn = 2007;
bool used[maxn];
int n, k;

int dist(int x1, int x2) {
    if (x2 >= x1)
        return x2 - x1;
    return x2 - x1 + 2 * n;
}

bool check(int x1, int x2, int x3, int x4) {
    int len = dist(x1, x2) + dist(x2, x3) + dist(x3, x4) + dist(x4, x1);
    return len == 2 * n;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) {
        used[i] = 0;
    }
    vector<pii> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i].ff >> a[i].ss;
        a[i].ff--;
        a[i].ss--;
        used[a[i].ff] = 1;
        used[a[i].ss] = 1;
    }
    vector<int> kek;
    for (int i = 0; i < 2 * n; i++) {
        if (!used[i]) {
            kek.pb(i);
        }
    }
//    int ans = 0;
    for (int i = 0; i < n - k; i++) {
        a.pb(kek[i], kek[i + n - k]);
//        int x2 = kek[i + n - k];
//        for (int e = 0; e < k; e++) {
//            int y1 = a[e].ff;
//            int y2 = a[e].ss;
//            if (check(x1, y1, x2, y2) || check(x1, y2, x2, y1)) {
//                ans++;
//            }
//        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int e = i + 1; e < n; e++) {
            if (check(a[i].ff, a[e].ff, a[i].ss, a[e].ss) || check(a[i].ff, a[e].ss, a[i].ss, a[e].ff)) {
                ans++;
//                cout << a[i].ff << a[e].ff << a[i].ss << a[e].ss << "\n";
            }
        }
    }
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