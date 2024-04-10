#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1000002, logN = 19, K = 111, M = 1000006, INF = 1e9 + 87;

struct TwoDimensionAddAndSum {
    // 0-index
    struct Seg {
        int l, r, m;
        long long vala, valb, lza, lzb;
        Seg* ch[2];
        Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), vala(0), valb(0), lza(0), lzb(0) {
            if (r - l > 1) {
                ch[0] = new Seg(l, m);
                ch[1] = new Seg(m, r);
            }
        }
        void pull() {vala = ch[0]->vala + ch[1]->vala, valb = ch[0]->valb + ch[1]->valb;}
        void give(lli a, lli b) {
            lza += a, lzb += b;
            vala += a * (r - l), valb += b * (r - l);
        }
        void push() {
            ch[0]->give(lza, lzb), ch[1]->give(lza, lzb), lza = lzb = 0;
        }
        void add(int a, int b, int va, int vb) {
            if (a <= l && r <= b)
                give(va, vb);
            else {
                push();
                if (a < m)
                    ch[0]->add(a, b, va, vb);
                if (m < b)
                    ch[1]->add(a, b, va, vb);
                pull();
            }
        }
        long long query(int a, int b, int v) {
            if (a <= l && r <= b)
                return vala * v + valb;
            push();
            long long ans = 0;
            if (a < m)
                ans += ch[0]->query(a, b, v);
            if (m < b)
                ans += ch[1]->query(a, b, v);
            return ans;
        }
    };
    // note integer overflow.
    vector <array <int, 4>> E[N];
    vector <array <int, 4>> Q[N];
    vector <long long> ans;

    void add_event(int x1, int y1, int x2, int y2, int v) {
        E[x1].pb({y1, y2,  v, -v * x1});
        E[x2].pb({y1, y2, -v, v * x2});
    }
    void add_query(int x1, int y1, int x2, int y2, int id) {
        Q[x1].pb({y1, y2, -1, id});
        Q[x2].pb({y1, y2, 1, id});
        ans.pb(0);
    }
    void run(int n) {
        Seg root(0, n);
        for (int i = 0; i <= n; ++i) {
            for (auto j : E[i])
                root.add(j[0], j[1], j[2], j[3]);
            for (auto j : Q[i])
                ans[j[3]] += j[2] * root.query(j[0], j[1], i);
        }
    }
} solver;

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    vector <int> p(n), to_pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i], to_pos[p[i]] = i;
    }
    vector <int> l(n), r(n);
    {
        stack <int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && p[stk.top()] < p[i])
                stk.pop();
            l[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
    }
    {
        stack <int> stk;
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && p[stk.top()] < p[i])
                stk.pop();
            r[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
    }
    vector <vector <pii>> Q(n);
    for (int i = 1; i <= n; ++i) for (int j = i + 1; 1ll * i * j <= n; ++j) {
        int k = i * j;
        int a = to_pos[i], b = to_pos[j], c = to_pos[k];
        int mn = min({a, b, c}), mx = max({a, b, c});
        if (l[c] < mn && mx < r[c])
            Q[c].eb(mn, mx);
    }
    for (int i = 0; i < n; ++i) {
        sort(all(Q[i]), [&](pii i, pii j) {
            if (i.X == j.X)
                return i.Y > j.Y;
            return i.X < j.X;
        });
        vector <pii> nxt;
        for (auto [l, r] : Q[i]) {
            while (!nxt.empty() && nxt.back().Y >= r)
                nxt.pop_back();
            nxt.eb(l, r);
        }
        for (int j = 0; j < nxt.size(); ++j) {
            if (j) 
                solver.add_event(nxt[j - 1].X + 1, nxt[j].Y, nxt[j].X + 1, r[i], 1);
            else
                solver.add_event(l[i] + 1, nxt[j].Y, nxt[j].X + 1, r[i], 1);
        }
    }
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r, --l;
        solver.add_query(l, l, r, r, i);
    }
    solver.run(n);
    for (int i = 0; i < q; ++i)
        cout << solver.ans[i] << '\n';
}