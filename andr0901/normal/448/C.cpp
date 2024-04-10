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

template <typename T>
class SparseTable {
private:
    int n, logn;

    vector <vector <T>> table;
    vector <int> lg;

public:
    SparseTable(const vector <T>& a = vector <T> ()) : n(a.size()) {
        lg.resize(n + 1);
        forn (i, 2, n + 1)
            lg[i] = lg[i / 2] + 1;
        logn = lg[n] + 1;

        table.resize(n, vector <T> (logn, {1e9 + 5, -1}));
        forn (i, 0, n)
            table[i][0] = a[i];
        forn (j, 1, logn)
            for (int i = 0; i + (1 << j - 1) < n; ++i)
                table[i][j] = min(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
    }

    //[l, r)
    T get(int l, int r) {
        int p = lg[r - l];
        return min(table[l][p], table[r - (1 << p)][p]);
    }
};

SparseTable <pii> t;

long long solve(int l, int r, long long delta) {
    if (r - l < 1)
        return 0;
    if (r - l == 1) {
        if (t.get(l, l + 1).fs <= delta)
            return 0;
        return 1;
    }
    auto [val, idx] = t.get(l, r);
    return min(1LL * r - l, val - delta + 
                            solve(l, idx, val) +
                            solve(idx + 1, r, val));
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a(n);
    forn (i, 0, n) {
        cin >> a[i].fs;
        a[i].sc = i;
    }
    t = SparseTable <pii> (a);
    cout << solve(0, n, 0);
    return 0;
}