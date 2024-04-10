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

const int maxn = 1e5 + 9;
int a[maxn];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int C = n;
    for (int j = 0; j < C; j++) {
        bool fl = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] % (i + 2) != 0) {
                fl = 1;
                for (int e = i; e < n - 1; e++) {
                    a[e] = a[e + 1];
                }
                n--;
                break;
            }
        }
        if (!fl) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}