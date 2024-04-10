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
        return max(a, b);
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
        for (i += n, chkmax(tr[i], x); i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn (i, 0, n) {
        cin >> a[i];
        --a[i];
    }
    vector<int> cnt(n);
    int mx = 0;
    vector<int> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        cnt[a[i]]++;
        chkmax(mx, cnt[a[i]]);
        suf[i] = mx;
    }
    vector<vector<int>> idxs(n);
    forn (i, 0, n)
        idxs[a[i]].pb(i);
    vector<pair <int, pii>> pairs;
    forn (i, 0, n)
        if (!idxs[i].empty())
            pairs.pb({idxs[i][0], {idxs[i].back(), idxs[i].size()}});
    sort(all(pairs));
    Segtree<int> tr(n + 1);
    forn (i, 0, sz(pairs)) {
        int l = pairs[i].fs, r = pairs[i].sc.fs, cnt = pairs[i].sc.sc;
        tr.upd(r + 1, tr.get(0, l + 1) + cnt);
    }
    cerr << suf << "\n";
    int ans = 0;
    forn (i, 0, n + 1)
        chkmax(ans, tr.get(i, i + 1) + suf[i]);
    cout << n - ans;
    return 0;
}