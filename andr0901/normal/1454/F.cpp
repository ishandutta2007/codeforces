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
class SparseTable_mn {
private:
    int n, logn;

    vector <vector <T>> table;
    vector <int> lg;

public:
    SparseTable_mn(const vector <T>& a = vector <T> ()) : n(a.size()) {
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
    T get(int l, int r) {
        ++r;
        int p = lg[r - l];
        return min(table[l][p], table[r - (1 << p)][p]);
    }
};

template <typename T>
class SparseTable_mx {
private:
    int n, logn;

    vector <vector <T>> table;
    vector <int> lg;

public:
    SparseTable_mx(const vector <T>& a = vector <T> ()) : n(a.size()) {
        lg.resize(n + 1);
        forn (i, 2, n + 1)
            lg[i] = lg[i / 2] + 1;
        logn = lg[n] + 1;

        table.resize(n, vector <T> (logn));
        forn (i, 0, n)
            table[i][0] = a[i];
        forn (j, 1, logn)
            for (int i = 0; i + (1 << j - 1) < n; ++i)
                table[i][j] = max(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
    }

    //[l, r)
    T get(int l, int r) {
        ++r;
        int p = lg[r - l];
        return max(table[l][p], table[r - (1 << p)][p]);
    }
};
/*
template <typename T = int>
class SparseTable_mx {
private:
    int n;
    vector <T> tr;
    T neutral_tr = -1;

    T merge(T a, T b) {
        return max(a, b);
    }

    template <typename U>
    void build(vector <U>& a) {
        forn (i, 0, n)
            tr[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    template <typename U = int>
    SparseTable_mx(vector <U> a = vector <U> ()) : n(sz(a)) {
        tr.resize(2 * n, neutral_tr);
        build(a);
    }

    T get(int l, int r) {
        cerr << l << " " << r << "\n";
        ++r;
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
        for (i += n, tr[i] += x; i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};

template <typename T = int>
class SparseTable_mn {
private:
    int n;
    vector <T> tr;
    T neutral_tr = 1e9 + 5;

    T merge(T a, T b) {
        return min(a, b);
    }

    template <typename U>
    void build(vector <U>& a) {
        forn (i, 0, n)
            tr[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    template <typename U = int>
    SparseTable_mn(vector <U> a = vector <U> ()) : n(sz(a)) {
        tr.resize(2 * n, neutral_tr);
        build(a);
    }

    T get(int l, int r) {
        ++r;
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
        for (i += n, tr[i] += x; i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};*/


int n;
vector <int> a;
SparseTable_mn <int> mn_table;
SparseTable_mx <int> mx_table;

int greater_right(int i) {
    int l = i, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (mx_table.get(i, m) == a[i])
            l = m;
        else
            r = m;
    }
    return r;
}

int lesser_right(int i) {
    int l = i, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (mn_table.get(i, m) == a[i])
            l = m;
        else
            r = m;
    }
    return r;
}

int greater_left(int i) {
    int l = -1, r = i;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (mx_table.get(m, i) == a[i])
            r = m;
        else
            l = m;
    }
    return l;
}

int lesser_left(int i) {
    int l = -1, r = i;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (mn_table.get(m, i) == a[i])
            r = m;
        else
            l = m;
    }
    return l;
}


void solve() {
    cin >> n;
    a = vector <int> (n);
    cin >> a;
    mn_table = SparseTable_mn(a), mx_table = SparseTable_mx(a);
    cerr << greater_right(1) << " ";
    forn (i, 0, n) {
        cerr << greater_left(i) << " " << greater_right(i) << " ";
        cerr << lesser_left(i) << " " << lesser_right(i) << "\n";
    }
    cerr << "\n";
    // cerr << mx_table.get(7, 8) << "\n";
    map <int, vector <int>> mp;
    forn (i, 0, n)
        mp[a[i]].pb(i);
    for (auto& [val, idxs] : mp) {
        if (idxs.size() < 3)
            continue;
        if (mx_table.get(0, idxs[0]) != val ||
            mx_table.get(idxs.back(), n - 1) != val)
            continue;
        int l = greater_right(idxs[0]), r = greater_left(idxs.back());
        forn (i, 1, idxs.size() - 1) {
            int cur_l = lesser_left(idxs[i]), cur_r = lesser_right(idxs[i]);
            // cerr << l << " " << r << "   " << cur_l << " " << cur_r << "\n";
            if (cur_l <= l && r <= cur_r) {
                chkmax(cur_l, idxs[0]);
                chkmin(cur_r, idxs.back());
                cout << "YES\n";
                int t_1 = cur_l + 1;
                int t_2 = cur_r - t_1;
                int t_3 = n - t_1 - t_2;
                assert(t_1 >= 1 && t_2 >= 1 && t_3 >= 1);
                cout << t_1 << " " << t_2 << " " << t_3 << "\n";
                return;
            }
        }
    }
    cerr << "\n";
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}