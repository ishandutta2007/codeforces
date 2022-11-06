#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };

void solve(istream& cin, ostream& cout) {
    int n, t;
    cin >> n >> t;
    vector<pair<int, pair<int, int>>> a(n);
    rep(i, 0, n) {
        cin >> a[i].second.first >> a[i].first;
        a[i].second.second = i;
    }
    sort(a.begin(), a.end());
    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        int ct = 0;
        int k = 0;
        rep(i, 0, n) {
            if (a[i].second.first >= m && a[i].first + ct <= t) {
                k++;
                ct += a[i].first;
            }
        }
        if (k >= m) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << "\n" << l << "\n";
    int ct = 0;
    int k = 0;
    rep(i, 0, n) {
        if (a[i].second.first >= l && a[i].first + ct <= t) {
            if (k < l) {
                k++;
                cout << a[i].second.second + 1 << " ";
            }
            ct += a[i].first;
        }
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}