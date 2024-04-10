#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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

const int MOD = 1e9 + 7;

class SegTree{
private: 
    int n;
    vector <int> tr, to_add;
    int neutral_tr = 0, neutral_to_add = 0;

    int merge_tr(int a, int b) {
        return (a + b) % MOD;
    }

    int merge_to_add(int a, int b) {
        return (a + b) % MOD;
    }

    void build(int v, int vl, int vr, const vector <int>& a) {
        if (vr - vl < 1)
            return;
        if (vr - vl == 1) {
            tr[v] = a[vl];
            return;
        }
        int vm = vl + vr >> 1;
        build(2 * v, vl, vm, a), build(2 * v + 1, vm, vr, a);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    void push(int v, int vl, int vr) {
        if (vr - vl != 1) {
            to_add[2 * v] = merge_to_add(to_add[2 * v], to_add[v]);
            to_add[2 * v + 1] = merge_to_add(to_add[2 * v + 1], to_add[v]);
        }
        tr[v] = merge_to_add(tr[v], to_add[v]);
        to_add[v] = neutral_to_add;
    }

    void upd(int v, int vl, int vr, int l, int r, int x) {
        push(v, vl, vr);
        if (vr <= l || r <= vl) 
            return;
        if (l <= vl && vr <= r) {
            to_add[v] = merge_to_add(to_add[v], x);
            push(v, vl, vr);
            return;
        }
        int vm = vl + vr >> 1;
        upd(2 * v, vl, vm, l, r, x), upd(2 * v + 1, vm, vr, l, r, x);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    int get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return neutral_tr;
        if (l <= vl && vr <= r)
            return tr[v];
        int vm = vl + vr >> 1;
        return merge_tr(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }
public:
    SegTree(int _n = 0) : n(_n) {
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
    }

    SegTree(const vector <int>& a) {
        n = sz(a);
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
        build(1, 0, n, a);
    }

    void upd(int l, int r, int x) {
        upd(1, 0, n, l, r, x);
    }

    int get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <char>> grid(n + 1, vector <char> (m + 1));
    forn (i, 0, n) 
        forn (j, 0, m)
            cin >> grid[i][j];
    vector <vector <int>> suf_rows(n, vector <int> (m + 1)), 
                          suf_columns(n + 1, vector <int> (m));
    forn (i, 0, n)
        for (int j = m - 1; j >= 0; j--)
            suf_rows[i][j] = suf_rows[i][j + 1] + (grid[i][j + 1] == 'R');
    forn (j, 0, m)
        for (int i = n - 1; i >= 0; i--)
            suf_columns[i][j] = suf_columns[i + 1][j] + (grid[i + 1][j] == 'R');
    //vector <SegTree> from_left(n, SegTree(m)), from_up(m, SegTree(n));
    vector <vector <int>> from_left(n, vector <int> (m));
    vector <vector <int>> from_up(m, vector <int> (n));
    vector <vector <int>> to_add_from_left(n + 1, vector <int> (m + 1));
    vector <vector <int>> to_add_from_up(m + 1, vector <int> (n + 1));
    to_add_from_left[0][0] = to_add_from_up[0][0] = 1;
    to_add_from_up[0][1] = to_add_from_left[0][1] = (-1 + MOD) % MOD;
    forn (i, 0, n) {
        forn (j, 0, m) {
            from_left[i][j] = to_add_from_left[i][j];
            if (j)
                from_left[i][j] = (from_left[i][j] + from_left[i][j - 1]) % MOD;

            from_up[j][i] = to_add_from_up[j][i];
            if (i)
                from_up[j][i] = (from_up[j][i] + from_up[j][i - 1]) % MOD;

            to_add_from_left[i][j + 1] = (to_add_from_left[i][j + 1] + from_up[j][i]) % MOD;
            to_add_from_left[i][m - suf_rows[i][j]] = (to_add_from_left[i][m - suf_rows[i][j]] - from_up[j][i] + MOD) % MOD;

            to_add_from_up[j][i + 1] = (to_add_from_up[j][i + 1] + from_left[i][j]) % MOD;
            to_add_from_up[j][n - suf_columns[i][j]] = (to_add_from_up[j][n - suf_columns[i][j]] - from_left[i][j] + MOD) % MOD;

            //from_left[i].upd(j + 1, m - suf_rows[i][j], from_up[j].get(i, i + 1));
            //from_up[j].upd(i + 1, n - suf_columns[i][j], from_left[i].get(j, j + 1));
        }
    }/*
    forn (i, 0, n) {
        forn (j, 0, m)
            cout << from_up[j][i] << " \n"[j == m - 1];
    }
    cout << "\n";
    forn (i, 0, n)
        forn (j, 0, m)
            cout << to_add_from_up[j][i] << " \n"[j == m - 1];
    
    forn (i, 0, n) {
        forn (j, 0, m) {
            cout << suf_rows[i][j] << " \n"[j == m - 1];
        }
    }
    cout << "\n";
    forn (i, 0, n) {
        forn (j, 0, m) {
            cout << suf_columns[i][j] << " \n"[j == m - 1];
        }
    }
    cout << "\n";
    forn (i, 0, n) {
        forn (j, 0, m)
            cout << from_up[i].get(j, j + 1) << " \n"[j == m - 1];
    }
    cout << "\n";
    forn (i, 0, n) {
        forn (j, 0, m) {
            cout << from_left[j].get(i, i + 1) << " \n"[j == m - 1];
        }
    }*/
    if (n == 1 && m == 1)
        cout << 1;
    else
        cout << (from_left[n - 1][m - 1] + from_up[m - 1][n - 1]) % MOD;
        //cout << (from_left[n - 1].get(m - 1, m) + from_up[m - 1].get(n - 1, n)) % MOD;
    return 0;
}