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

#define x first
#define y second

const int C = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pii> a(n), b(m);
    forn (i, 0, n)
        cin >> a[i].x >> a[i].y;
    forn (i, 0, m)
        cin >> b[i].x >> b[i].y;
    sort(rall(b));
    int mx = -1;
    vector <int> border(C, -1);
    forn (i, 0, m) {
        if (i) {
            forn (j, b[i].x + 1, b[i - 1].x + 1)
                border[j] = mx;
        }
        chkmax(mx, b[i].y);
    }
    forn (i, 0, b[m - 1].x + 1)
        border[i] = mx;
    /**forn (i, 0, C)
        cerr << i << ": " << border[i] << "\n";*/
    vector <vector <pii>> interesting(C);
    forn (i, 0, n) {
        forn (j, 0, m)
            if (b[j].x - a[i].x + 1 >= 0)
                interesting[b[j].x - a[i].x + 1].eb(i, j);
    }
    multiset <int> everything;
    vector <int> dst;
    for (auto [x, y] : a) {
        dst.pb(max(border[x] - y + 1, 0));
        everything.insert(dst.back());
    }
    cerr << dst << "\n";
    int ans = *everything.rbegin();
    forn (dx, 0, C) {
        for (auto [i, j] : interesting[dx]) {
            if (max(0, border[b[j].x + 1] - a[i].y + 1) < dst[i]) {
                everything.erase(everything.find(dst[i]));
                dst[i] = max(0, border[b[j].x + 1] - a[i].y + 1);
                everything.insert(dst[i]);
            }
        }
        chkmin(ans, *everything.rbegin() + dx);
        // cerr << dx << ":  " << dst << "\n";
    }
    cout << ans;
    return 0;
}