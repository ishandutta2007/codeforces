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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}


void solve() {
    int n;
    cin >> n;
    vector <vector <int>> idxs(n);
    forn (i, 0, n) {
        int x;
        cin >> x;
        idxs[x - 1].pb(i);
    }
    long long ans = 0;
    forn (fs, 0, n) {
        forn (sc, fs + 1, n) {
            {
                auto &x = idxs[fs], &y = idxs[sc]; 
                vector <int> right(sz(x));
                forn (i, 0, sz(x))
                    forn (j, 0, sz(y))
                        if (y[j] > x[i])
                            right[i]++;
                int s = accumulate(all(right), 0);
                forn (i, 0, sz(x)) {
                    int k = 0;
                    int sum = s;
                    forn (j, 0, sz(y)) {
                        if (x[i] >= y[j])
                            continue;
                        while (k < sz(x) && x[k] <= y[j]) {
                            sum -= right[k];
                            ++k;
                        }
                        ans += sum;
                    }
                }
            }
            {
                auto &x = idxs[sc], &y = idxs[fs];
                vector <int> right(sz(x));
                forn (i, 0, sz(x))
                    forn (j, 0, sz(y))
                        if (y[j] > x[i])
                            right[i]++;
                int s = accumulate(all(right), 0);
                forn (i, 0, sz(x)) {
                    int k = 0;
                    int sum = s;
                    forn (j, 0, sz(y)) {
                        if (x[i] >= y[j])
                            continue;
                        while (k < sz(x) && x[k] <= y[j]) {
                            sum -= right[k];
                            ++k;
                        }
                        ans += sum;
                    }
                }
            }
        }
    }
    forn (i, 0, n) {
        int t = sz(idxs[i]);
        if (t >= 4)
            ans += 1LL * t * (t - 1) * (t - 2) * (t - 3) / 24;
    }
    cout << ans << "\n";
}

main() {
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}