#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;

const int M = 1e9 + 7;

int main() {
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    lint ans = 0;
    lint p2 = 1;
    lint add = 0;
    for (int i = 1; i < n; i++) {
        p2 = p2 * 2 % M;
        add = (add * 2 + (p2 - 1) * (a[i] - a[i - 1])) % M;
        ans = (ans + add) % M;
    }

    cout << ans;

    return 0;
}