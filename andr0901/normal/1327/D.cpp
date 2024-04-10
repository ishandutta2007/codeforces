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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <vector <int>> divisors;

void find_divisors(int x) {
    for (int i = 1; i * i <= x; ++i)
        if (x % i == 0)
            divisors[x].pb(i), divisors[x].pb(x / i);
}

void solve() {
    int n;
    cin >> n;
    vector <int> p(n);
    forn (i, 0, n)
        cin >> p[i], --p[i];
    vector <int> c(n);
    cin >> c;
    vector <bool> used(n);
    int ans = 1e9;
    forn (i, 0, n) {
        if (used[i])
            continue;
        vector <int> cycle;
        int cur = i;
        do {
            used[cur] = true;
            cycle.pb(cur);
            cur = p[cur];
        } while (cur != i);
        vector <int> col;
        for (int j : cycle)
            col.pb(c[j]);
        for (int j : cycle)
            col.pb(c[j]);

        for (int j : divisors[sz(cycle)]) {
            for (int k = 0; k < j; ++k) {
                bool ok = true;
                for (int l = k; l < sz(col); l += j)
                    if (col[l] != col[k])
                        ok = false;
                if (ok)
                    chkmin(ans, j);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    divisors.resize(2e5 + 10);
    forn (i, 1, sz(divisors)) {
        find_divisors(i);
    }
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}