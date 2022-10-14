#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17;

vector <int> v;

struct line {
    lli m = 0, k = -1ll << 60;
    lli operator () (lli _v) {
        return m * _v + k;
    }
} node[N * 4];

struct op {
    int id;
    line from;
};

stack <op> OP;
stack <int> point;
vector <pii> ask;

void add_line(line cur, int l = 0, int r = v.size(), int id = 1) {
    if (r - l == 1) {
        if (node[id](v[l]) < cur(v[l])) {
            OP.push({id, node[id]});
            swap(node[id], cur);
        }
    } else {
        int m = l + r >> 1;
        if (node[id].m < cur.m) {
            OP.push({id, node[id]});
            swap(node[id], cur);
        }
        if (node[id](v[m]) < cur(v[m])) {
            OP.push({id, node[id]});
            swap(node[id], cur);
            add_line(cur, m, r, id << 1 | 1);
        } else {
            add_line(cur, l, m, id << 1);
        }
    }
}

lli query(int x, int l = 0, int r = v.size(), int id = 1) {
    if (r - l == 1) return node[id](v[l]);
    int m = l + r >> 1;
    if (x < m) return max(node[id](v[x]), query(x, l, m, id << 1));
    return max(node[id](v[x]), query(x, m, r, id << 1 | 1));
}

void rollback() {
    int pt = point.top(); point.pop();
    while (OP.size() > pt) {
        op O = OP.top(); OP.pop();
        node[O.id] = O.from;
    }
}

vector <lli> ans;

struct Seg {
    vector <line> event;
    Seg* ch[2];
    Seg (int l, int r) {
        if (r - l > 1) {
            ch[0] = new Seg(l, l + r >> 1);
            ch[1] = new Seg(l + r >> 1, r);
        }
    }
    void add_event(int a, int b, line L, int l, int r) {
        if (a <= l && r <= b) event.pb(L);
        else {
            int m = l + r >> 1;
            if (a < m) ch[0]->add_event(a, b, L, l, m);
            if (m < b) ch[1]->add_event(a, b, L, m, r);
        }
    }
    void run(int l, int r) {
        point.push(OP.size());
        for (line &L : event) {
            add_line(L);
        }
        if (r - l == 1) {
            if (ask[l].Y != -1) {
                ans[ask[l].Y] = query(lower_bound(all(v), ask[l].X) - v.begin());
            }
        } else {
            ch[0]->run(l, l + r >> 1);
            ch[1]->run(l + r >> 1, r);
        }
        rollback();
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    vector <line> pre(q, {0, 0});
    set <int> s;
    ask.assign(q, mp(-1, -1));
    Seg root(0, q);
    for (int i = 0, type, k; i < q; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> pre[i].m >> pre[i].k;
            s.insert(i);
        } else if (type == 2) {
            cin >> k, k--;
            s.erase(k);
            root.add_event(k, i + 1, pre[k], 0, q);
        } else {
            cin >> k;
            ask[i] = mp(k, ans.size());
            v.pb(k);
            ans.pb(0);
        }
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    if (v.empty()) return 0;
    for (int i : s) {
        root.add_event(i, q, pre[i], 0, q);
    }
    root.run(0, q);
    for (lli &i : ans) {
        if (i > -1ll << 60) cout << i << '\n';
        else cout << "EMPTY SET\n";
    }
}