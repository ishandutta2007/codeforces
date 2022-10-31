#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

struct Node{
    int sum, mx, idx, team;
    Node(int _sum, int _mx, int _idx, int _team) {sum = _sum, mx = _mx, idx = _idx, team = _team;}
};

Node merge(Node a, Node b) {
    if (a.mx > b.mx)
        return {a.sum + b.sum, a.mx, a.idx, min(a.team, b.team)};
    else 
        return {a.sum + b.sum, b.mx, b.idx, min(a.team, b.team)};
}

vector <int> a, to_add;
vector <Node> tr;
const int INF = 1e9;

void build(int v, int vl, int vr) {
    if (vr - vl == 1) {
        tr[v] = {1, a[vl], vl, INF};
        return;
    }
    int vm = vl + vr >> 1;
    build(2 * v, vl, vm), build(2 * v + 1, vm, vr);
    tr[v] = merge(tr[2 * v], tr[2 * v + 1]);
}

void push(int v, int vl, int vr) {
    if (to_add[v] == INF)
        return;
    if (vr - vl != 1) {
        to_add[2 * v] = min(to_add[2 * v], to_add[v]);
        to_add[2 * v + 1] = min(to_add[2 * v + 1], to_add[v]);
    }
    tr[v].sum = tr[v].mx = 0;
    tr[v].team = min(tr[v].team, to_add[v]);
    to_add[v] = INF;
}

void upd(int v, int vl, int vr, int l, int r, int val) {
    push(v, vl, vr);
    if (vr <= l || r <= vl)
        return;
    if (l <= vl && vr <= r) {
        to_add[v] = min(to_add[v], val);
        push(v, vl, vr);
        return;
    }
    int vm = vl + vr >> 1;
    upd(2 * v, vl, vm, l, r, val), upd(2 * v + 1, vm, vr, l, r, val);
    tr[v] = merge(tr[2 * v], tr[2 * v + 1]);
}

Node get(int v, int vl, int vr, int l, int r) {
    push(v, vl, vr);
    if (vr <= l || r <= vl)
        return {0, 0, 0, INF};
    if (l <= vl && vr <= r)
        return tr[v];
    int vm = vl + vr >> 1;
    return merge(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    a.resize(n);
    forn (i, 0, n) 
        cin >> a[i];
    tr.resize(4 * n, {0, 0, 0, INF}), to_add.resize(4 * n, INF);
    build(1, 0, n);
    forn (i, 0, n) {
        Node q1 = get(1, 0, n, 0, n);
        if (q1.mx == 0)
            break;
        //cout << q1.idx << " ";
        int l = -1, r = max(0, q1.idx - 1);
        while (r - l > 1) {
            int m = l + r >> 1;
            if (get(1, 0, n, m, q1.idx).sum <= k)
                r = m;
            else 
                l = m;
        }
        //cout << r << " ";
        upd(1, 0, n, r, q1.idx, i);
        l = min(n - 1, q1.idx + 1), r = n;
        while (r - l > 1) {
            int m = l + r >> 1;
            if (get(1, 0, n, q1.idx + 1, m + 1).sum <= k)
                l = m;
            else 
                r = m;
        }
        //cout << l << "\n";
        upd(1, 0, n, q1.idx, r, i);
    }
    forn (i, 0, n) {
        if (get(1, 0, n, i, i + 1).team % 2)
            cout << 2;
        else 
            cout << 1;
    }
    return 0;
}