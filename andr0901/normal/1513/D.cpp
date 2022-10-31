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
};

vector<int> a;

int find_left(int i, const SparseTable<int>& sparse_table) {
    int l = -1, r = i;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (sparse_table.get_seg(m, i) == a[i]) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

int find_right(int i, const SparseTable<int>& sparse_table) {
    int l = i, r = a.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (sparse_table.get_seg(i, m) == a[i]) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

pair<int, int> find_relevant_segment(int i, const SparseTable<int>& sparse_table) {
    return {find_left(i, sparse_table), find_right(i, sparse_table)};
}

void solve() {
    int n, p;
    cin >> n >> p;
    a.resize(n);
    cin >> a;
    SparseTable<int> sparse_table(a);
    // forn (i, 0, n) {
    //     cerr << sparse_table.get_seg(0, i) << " "; 
    // }
    map<int, vector<int>> open;
    map<int, vector<int>> close;
    forn (i, 0, n) {
        auto [l, r] = find_relevant_segment(i, sparse_table);
        if (l == r) {
            continue;
        }
        open[l].push_back(a[i]);
        close[r - 1].push_back(a[i]);
    }
    long long ans = 0;
    multiset<int> mins = {p};
    forn (i, 0, n) {
        while (!open[i].empty()) {
            mins.insert(open[i].back());
            open[i].pop_back();
        }
        cerr << *mins.begin() << " ";
        if (i < n - 1) {
            ans += *mins.begin();
        }
        while (!close[i].empty()) {
            mins.erase(mins.find(close[i].back()));
            close[i].pop_back();
        }
    }
    cout << ans << "\n";
    cerr << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}