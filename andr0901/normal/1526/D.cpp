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
class Segtree {
private:
    int n;
    vector <T> tr;
    T neutral_tr = 0;

    T merge(T a, T b) {
        return a + b;
    }

    template <typename U>
    void build(const vector <U>& a) {
        forn (i, 0, n)
            tr[i + n] = a[i];
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
        T ans = neutral_tr;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2)
                ans = merge(ans, tr[l++]);
            if (r % 2)
                ans = merge(ans, tr[--r]);
        }
        return ans;
    }

    void upd(int i, int x) {
        for (i += n, tr[i] = x; i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};

map<char, int> mapping = {
    {'A', 0},
    {'N', 1},
    {'O', 2},
    {'T', 3}
};

map<char, int> rev_mapping = {
    {0, 'A'},
    {1, 'N'},
    {2, 'O'},
    {3, 'T'}
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(4);
    for (char c : s) {
        cnt[mapping[c]]++;
    }
    vector<int> p(4);
    iota(all(p), 0);
    pair<long long, vector<int>> ans = {-1, {}};
    do {
        vector<int> firsts(4);
        int sum = 0;
        forn (i, 0, 4) {
            int cur = p[i];
            firsts[cur] = sum;
            sum += cnt[cur];
        }
        Segtree<int> tr(vector<int>(n, 1));
        long long cur = 0;
        for (char c : s) {
            int i = mapping[c];
            cur += tr.get(0, firsts[i]);
            tr.upd(firsts[i], 0);
            firsts[i]++;
        }
        chkmax(ans, make_pair(cur, p));
    } while (next_permutation(all(p)));
    cerr << ans.fs << " " << ans.sc << "\n";
    for (int i : ans.sc) {
        cout << string(cnt[i], rev_mapping[i]);
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}