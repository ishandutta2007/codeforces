#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#define pb push_back
#define all(a) a.begin(),a.end()
#define foi(n) for (int i = 0; i < n; i++)
#define foj(n) for (int j = 0; j < n; j++)
#define fo(i, n) for (int i = 0; i < n; i++)
#define vei vector<int>
#define pii pair<int, int>
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vei a(n);
    ll s = 0;
    foi(n) cin >> a[i], s += a[i];
    if (s % 3 != 0) {
        cout << 0;
        return;
    }
    vector<ll> r1(n);
    s /= 3;
    ll cs1 = s * 3;
    ll cs2 = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            r1[i] = r1[i + 1];
        }
        if (i < n - 1 && cs1 == 2 * s && cs2 == s) {
            r1[i] += 1;
        }
        cs2 += a[i];
        cs1 -= a[i];
    }
    ll cs = 0;
    ll ans = 0;
    foi(n - 1) {
        cs += a[i];
        if (cs == s) {
            ans += r1[i + 1];
        }
    }
    cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}