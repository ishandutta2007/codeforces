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
 
        table.resize(n, vector <T> (logn));
        forn (i, 0, n)
            table[i][0] = a[i];
        forn (j, 1, logn)
            for (int i = 0; i + (1 << j - 1) < n; ++i)
                table[i][j] = gcd(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
    }
 
    //[l, r)
    T get_half(int l, int r) const {
        int p = lg[r - l];
        return gcd(table[l][p], table[r - (1 << p)][p]);
    }
 
    T get_seg(int l, int r) const {
        return get_half(l, r + 1);
    }

    int size() const {
        return n;
    }
};

int bin_search(int i, int g, const SparseTable<int>& table) {
    int l = i - 1, r = table.size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (table.get_seg(i, m) != g) {
            l = m;
        } else {
            r = m;
        }
    }
    return r - i;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    forn (i, 0, n) {
        a.pb(a[i]);
    }
    SparseTable<int> table(a);
    int g = table.get_half(0, n);
    int ans = 0;
    forn (i, 0, n) {
        int cur = bin_search(i, g, table);
        cerr << cur << " ";
        chkmax(ans, cur);
    }
    cerr << "\n";
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