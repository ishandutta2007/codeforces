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

const int maxn = 100;
int a[maxn][maxn];

void solve() {
    int n, k;
    cin >> n >> k;
    if (k > (n + 1) / 2) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < n; e++) {
            if (i == e && i % 2 == 0 && k) {
                k--;
                cout << "R";
            } else {
                cout << ".";
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