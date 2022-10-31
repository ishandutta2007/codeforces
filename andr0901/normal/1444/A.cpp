//#pragma GCC optimize("Ofast")
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
    long long p, q;
    cin >> p >> q;
    if (p % q) {
        cout << p << "\n";
        return;
    }
    int mx = 0;
    vector <pii> d;
    for (int i = 2; i * i <= q; ++i) {
        if (q % i == 0) {
            int cnt = 0;
            while (q % i == 0) {
                ++cnt;
                q /= i;
            }
            d.eb(i, cnt);
        }
    }
    if (q > 1)
        d.eb(q, 1);
    long long ans = 0;
    forn (i, 0, sz(d)) {
        cerr << p << " ";
        int cnt = 0;
        while (p % d[i].fs == 0) {
            ++cnt;
            p /= d[i].fs;
        }
        cerr << d[i].fs << " " << d[i].sc << " " << cnt << "\n";
        forn (j, 0, d[i].sc - 1)
            p *= d[i].fs;
        chkmax(ans, p);
        forn (j, 0, d[i].sc - 1)
            p /= d[i].fs;
        forn (j, 0, cnt)
            p *= d[i].fs;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}