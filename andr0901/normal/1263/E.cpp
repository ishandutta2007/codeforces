#pragma GCC optimize("Ofast")
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

const int INF = 1e9;

struct Node {
    int mn, mx;
};

class SegTree{
private: 
    int n;
    vector <Node> tr;
    vector <int> to_add;
    Node neutral_tr = {INF, -INF};
    int neutral_to_add = 0;

    Node merge_tr(Node a, Node b) {
        return {min(a.mn, b.mn),
                max(a.mx, b.mx)};
    }

    int merge_to_add(int a, int b) {
        return a + b;
    }

    void build(int v, int vl, int vr) {
        if (vr - vl < 1)
            return;
        if (vr - vl == 1) {
            tr[v] = {0, 0};
            return;
        }
        int vm = vl + vr >> 1;
        build(2 * v, vl, vm), build(2 * v + 1, vm, vr);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    void push(int v, int vl, int vr) {
        if (vr - vl != 1) {
            to_add[2 * v] = merge_to_add(to_add[2 * v], to_add[v]);
            to_add[2 * v + 1] = merge_to_add(to_add[2 * v + 1], to_add[v]);
        }
        tr[v] = {tr[v].mn + to_add[v], tr[v].mx + to_add[v]};
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

    Node get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return neutral_tr;
        if (l <= vl && vr <= r)
            return tr[v];
        int vm = vl + vr >> 1;
        return merge_tr(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }
public: 
    SegTree(int _n) : n(_n) {
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
        build(1, 0, n);
    }

    void upd(int l, int r, int x) {
        upd(1, 0, n, l, r, x);
    }

    Node get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    SegTree tr(n + 1);
    string s;
    getline(cin, s);
    getline(cin, s);
    int cur = 0;
    vector <char> a(n + 1, '#');
    forn (i, 0, n) {
        //`cout << cur << " " << a[cur] << "\n";
        if (s[i] == 'R') {
            cur++;
        } else if (s[i] == 'L') {
            if (cur)
                cur--;
        } else if (s[i] == '(') {
            if (a[cur] == ')')
                tr.upd(cur, n + 1, 2);
            if (a[cur] == '#')
                tr.upd(cur, n + 1, 1);
            a[cur] = '(';
        } else if (s[i] == ')') {
            if (a[cur] == '(')
                tr.upd(cur, n + 1, -2);
            if (a[cur] == '#')
                tr.upd(cur, n + 1, -1);
            a[cur] = ')';
        } else {
            if (a[cur] == '(')
                tr.upd(cur, n + 1, -1);
            if (a[cur] == ')')
                tr.upd(cur, n + 1, 1);
            a[cur] = '#';
        }
        //cout << s[i] << " " << i << "\n";
        //cout << tr.get(0, n + 1).mn << " " << tr.get(0, n + 1).mx << " " << tr.get(n, n + 1).mn << "\n";
        auto query = tr.get(0, n + 1);
        if (query.mn == 0 && tr.get(n, n + 1).mn == 0)
            cout << query.mx;
        else
            cout << "-1";
        cout << " ";
    }
    return 0;
}