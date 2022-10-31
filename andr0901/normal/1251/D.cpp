#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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

int n;
ll s;
vector <pii> a;

bool check(int m) {
    ll cost = 0;
    vector <int> b;
    int first_group = 0;
    forn (i, 0, n) {
        if (a[i].sc < m) {
            first_group++;
            cost += a[i].fs;
        } else if (a[i].fs >= m) {
            cost += a[i].fs;
        } else {
            b.pb(a[i].fs);
        }
    }
    if (first_group > n / 2)
        return false;
    sort(all(b));
    forn (i, 0, sz(b)) {
        if (first_group < n / 2) {
            cost += b[i];
            first_group++;
        } else {
            cost += m;
        }
    }
    //cout << m << " " << cost << "\n";
    return cost <= s;
}

void solve() {
    cin >> n >> s;
    a.resize(n);
    forn (i, 0, n)
        cin >> a[i].fs >> a[i].sc;
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}