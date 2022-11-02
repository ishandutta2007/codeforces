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
//int a[maxn];

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        s.insert(a);
    }
    if (x == sum) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int cur = 0;
        while (!s.empty()) {
            int a = *s.begin();
            if (a + cur == x) {
                a = *s.rbegin();
                cout << a << " ";
                s.erase(--s.end());
                cur += a;
            } else {
                cout << a << " ";
                s.erase(s.begin());
                cur += a;
            }
        }
        cout << "\n";
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