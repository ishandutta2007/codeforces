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

#define int long long

constexpr int INF = 1e18 + 5;

template <typename T>
class Segtree {
private:
    int n;
    vector <T> tr;
    T neutral_tr = {INF, -INF};

    T merge(T a, T b) {
        return {min(a.fs, b.fs), max(a.sc, b.sc)};
    }

    template <typename U>
    void build(const vector <U>& a) {
        forn (i, 0, n)
            tr[i + n] = {a[i], a[i]};
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    template <typename U>
    Segtree(const vector <U>& a) : n(sz(a)) {
        tr.resize(2 * n, neutral_tr);
        build(a);
    }

    Segtree(int _n) : n(_n) {
        tr.resize(2 * n, neutral_tr);
    }

    T get(int l, int r) {
        cerr << "tr " << l << " " << r << "\n";
        T ans = neutral_tr;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2)
                ans = merge(ans, tr[l++]);
            if (r % 2)
                ans = merge(ans, tr[--r]);
        }
        return ans;
    }
};


void solve() {
    int n;
    cin >> n;
    vector <pii> queries(n + 1);
    forn (i, 0, n)
        cin >> queries[i].fs >> queries[i].sc;
    queries[n].fs = INF - 1;
    int t = 0, x = 0;
    vector <int> times = {0}, cords = {0};
    forn (i, 0, n) {
        if (queries[i].fs >= t) {
            times.pb(queries[i].fs);
            cords.pb(x);
            t = queries[i].fs + abs(queries[i].sc - x);
            x = queries[i].sc;
            times.pb(t);
            cords.pb(x);
        }
    }
    times.pb(INF), cords.pb(cords.back());
    cerr << times << "\n" << cords << "\n";
    int ans = 0;
    Segtree <pii> tr(cords);
    forn (i, 0, n) {
        int l = upper_bound(all(times), queries[i].fs) - times.begin();
        int r = upper_bound(all(times), queries[i + 1].fs) - times.begin();
        int k_l = (cords[l] - cords[l - 1]) / (times[l] - times[l - 1]);
        int x_l = cords[l] - k_l * (times[l] - queries[i].fs);
        int k_r = (cords[r] - cords[r - 1]) / (times[r] - times[r - 1]);
        int x_r = cords[r] - k_r * (times[r] - queries[i + 1].fs);
        int mn, mx;
        tie(mn, mx) = tr.get(l, r);
        mn = min({mn, x_l, x_r});
        mx = max({mx, x_l, x_r});
        if (mn <= queries[i].sc && queries[i].sc <= mx)
            ++ans;
        cerr << l << " " << r << ": ";
        cerr << x_l << " " << x_r << "\n";
    }
    cerr << "\n";
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}