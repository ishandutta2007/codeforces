#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    vector <int> a(m);
    forn (i, 0, m)
        cin >> a[i];
    sort(all(a));
    vector <vector <int>> b(k, vector <int> (3));
    forn (i, 0, k)
        forn (j, 0, 3)
            cin >> b[i][j];
    auto check = [&k, &b, &t, &n](int m) {
        vector <int> covered(2e5 + 1);
        forn (i, 0, k)
            if (b[i][2] > m)
                covered[b[i][0]]++, covered[b[i][1] + 1]--;
        int bal = 0, ans = 0;
        forn (i, 0, 2e5 + 1) {
            bal += covered[i];
            if (bal)
                ans++;
        }
        return n + 1 + ans * 2 <= t;
    };
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (check(m))
            r = m;
        else
            l = m;
    }
    cout << a.end() - lower_bound(all(a), r);
    return 0;
}