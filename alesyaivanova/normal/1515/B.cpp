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

bool check_sqrt(int k) {
    int s = sqrt(k);
    return (s * s == k || (s - 1) * (s - 1) == k || (s + 1) * (s + 1) == k);
}

void solve() {
    int n;
    cin >> n;
    bool fl = 0;
    if (n % 4 == 0 && check_sqrt(n / 4)) {
        fl = 1;
    }
    if (n % 2 == 0 && check_sqrt(n / 2)) {
        fl = 1;
    }
    if (fl) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}