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

const int maxn = 1e6 + 9;
int a[maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }
    if (a[0] > a[1]) {
        ans += a[0] - a[1];
        a[0] = a[1];
    }
    if (a[n - 1] > a[n - 2]) {
        ans += a[n - 1] - a[n - 2];
        a[n - 1] = a[n - 2];
    }
    for (int i = 1; i < n - 1; i++) {
//        cout << a[i - 1] << "      " << a[i] << " " << a[i + 1] << "\n";
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            ans += a[i] - max(a[i - 1], a[i + 1]);
            a[i] = max(a[i - 1], a[i + 1]);
//            cerr << i << " " << a[i] << "\n";
        }
    }
//    for (int i = 0; i < n; i++) {
//        cerr << a[i] << " ";
//    }
//    cerr << "\n";
    for (int i = 0; i < n - 1; i++) {
        ans += abs(a[i] - a[i + 1]);
    }
    ans += a[0] + a[n - 1];
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