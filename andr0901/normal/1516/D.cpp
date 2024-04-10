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

constexpr int N = 1e5 + 5;
constexpr int INF = 1e9;
constexpr int LOG = 20;

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
                table[i][j] = min(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
    }
 
    //[l, r)
    T get_half(int l, int r) const {
        int p = lg[r - l];
        return min(table[l][p], table[r - (1 << p)][p]);
    }
 
    T get_seg(int l, int r) const {
        return get_half(l, r + 1);
    }
 
    int size() const {
        return n;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> idxs(N);
    forn (i, 0, n) {
        int x = a[i];
        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                idxs[j].push_back(i);
                while (x % j == 0) {
                    x /= j;
                }
            }
        }
        if (x > 1) {
            idxs[x].push_back(i);
        }
    }
    vector<int> nxt(n, INF);
    forn (i, 0, N) {
        for (int j = static_cast<int>(idxs[i].size()) - 2; j >= 0; --j) {
            int l = idxs[i][j], r = idxs[i][j + 1];
            chkmin(nxt[l], r);
        }
    }
    cerr << nxt << "\n";
    vector<int> left(n);
    SparseTable<int> table(nxt);
    forn (i, 0, n) {
        int l = -1, r = i;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (table.get_seg(m, i) > i) {
                r = m;
            } else {
                l = m;
            }
        }
        left[i] = r;
    }
    cerr << left << "\n";
    vector<vector<int>> leaps(n, vector<int>(LOG));
    forn (i, 0, n)
        leaps[i][0] = left[i];
    forn (j, 1, LOG) {
        forn (i, 0, n) {
            int prev_idx = leaps[i][j - 1] - 1;
            if (prev_idx < 0) {
                leaps[i][j] = -1;
            } else {
                leaps[i][j] = leaps[prev_idx][j - 1];
            }
        }
        if (j < 10) {
            forn (i, 0, n) {
                cerr << leaps[i][j] << " ";
            }
            cerr << "\n";
        }
    }
    while (q --> 0) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int ans = 0;
        for (int i = LOG - 1; i >= 0; --i) {
            if (r >= 0 && l <= leaps[r][i]) {
                ans += (1 << i);
                r = leaps[r][i] - 1;
            }
        }
        if (l <= r) {
            ++ans;
        }
        cout << ans << "\n";
    }
    return 0;
}