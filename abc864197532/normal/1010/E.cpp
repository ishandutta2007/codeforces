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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 100005, logN = 18, G = 3;

template <typename T>
struct BIT {
    // single point add, prefix query sum
    vector <T> val;
    int n, offset;
    BIT () = default;
    BIT (int _n, int _offset = 3) : n(_n + _offset * 2), offset(_offset) {
        val.assign(n, 0);
    }
    void add(int p, T v) {
        for (p += offset; p < n; p += p & (-p))
            val[p] += v;
    }
    T query(int p) {
        T ans = 0;
        for (p += offset; p > 0; p -= p & (-p))
            ans += val[p];
        return ans;
    }
    T query(int l, int r) {
        // query [l, r)
        return query(r - 1) - query(l - 1);
    }
    int kth (int k) {
        // 1-index, return kth smallest number
        // 1 <= k && k <= current size
        int ans = 0;
        for (int i = 1 << __lg(n); i > 0; i >>= 1) {
            if (ans + i < n && val[ans + i] < k) k -= val[ans += i];
        }
        return ans - offset + 1;
    }
};

BIT <int> bit(N);

struct CDQ {
    struct event {
        int x, y, z, val, type;
        bool operator < (const event &o) {
            if (x == o.x)
                return type < o.type;
            return x < o.x;
        }
    };
    vector <event> E;
    int ans[N];
    void solve(int l, int r) {
        if (r - l == 1)
            return;
        int m = l + r >> 1;
        solve(l, m), solve(m, r);
        vector <event> now;
        vector <pii> mov;
        int i, j;
        for (i = l, j = m; j < r; ++j) {
            while (i < m && E[i].y <= E[j].y) {
                if (E[i].type == 0) {
                    bit.add(E[i].z, E[i].val), mov.eb(E[i].z, E[i].val);
                }
                now.pb(E[i++]);
            }
            if (E[j].type == 1)
                ans[E[j].val] += bit.query(E[j].z);
            now.pb(E[j]);
        }
        while (i < m) {
            now.pb(E[i++]);
        }
        for (int i = 0; i < now.size(); ++i) {
            E[l + i] = now[i];
        }
        for (auto [x, y] : mov)
            bit.add(x, -y);
    }
    void run() {
        if (E.empty())
            return;
        sort(all(E));
        solve(0, E.size());
    }
    void add_event(int x, int y, int z, int v, int ty) {
        E.pb({x, y, z, v, ty});
    }
} cdq;

int main () {
    owo;
    int A, B, C, n, m, q;
    cin >> A >> B >> C >> n >> m >> q;
    vector <array <int, 3>> good(n), bad(m);
    int lx = 1 << 30, rx = -1 << 30, ly = 1 << 30, ry = -1 << 30, lz = 1 << 30, rz = -1 << 30;
    for (int i = 0; i < n; ++i) for (int j = 0; j < 3; ++j)
        cin >> good[i][j];
    for (int i = 0; i < m; ++i) for (int j = 0; j < 3; ++j)
        cin >> bad[i][j];
    for (int i = 0; i < n; ++i) {
        lx = min(lx, good[i][0]);
        rx = max(rx, good[i][0]);
        ly = min(ly, good[i][1]);
        ry = max(ry, good[i][1]);
        lz = min(lz, good[i][2]);
        rz = max(rz, good[i][2]);
    }
    for (int i = 0; i < m; ++i) {
        if (lx <= bad[i][0] && bad[i][0] <= rx && ly <= bad[i][1] && bad[i][1] <= ry && lz <= bad[i][2] && bad[i][2] <= rz) {
            cout << "INCORRECT\n";
            return 0;
        }
    }
    cout << "CORRECT\n";
    int llx = -1 << 30, rrx = 1 << 30, lly = -1 << 30, rry = 1 << 30, llz = -1 << 30, rrz = 1 << 30;
    for (int i = 0; i < m; ++i) {
        int x1 = 1, y1 = 1, z1 = 1, x2 = A + 1, y2 = B + 1, z2 = C + 1;
        if (bad[i][0] < lx)
            x2 = bad[i][0] + 1;
        if (rx < bad[i][0])
            x1 = bad[i][0];
        if (bad[i][1] < ly)
            y2 = bad[i][1] + 1;
        if (ry < bad[i][1])
            y1 = bad[i][1];
        if (bad[i][2] < lz)
            z2 = bad[i][2] + 1;
        if (rz < bad[i][2])
            z1 = bad[i][2];
        cdq.add_event(x1, y1, z1, 1, 0);
        cdq.add_event(x1, y1, z2, -1, 0);
        cdq.add_event(x1, y2, z1, -1, 0);
        cdq.add_event(x2, y1, z1, -1, 0);
        cdq.add_event(x1, y2, z2, 1, 0);
        cdq.add_event(x2, y1, z2, 1, 0);
        cdq.add_event(x2, y2, z1, 1, 0);
        cdq.add_event(x2, y2, z2, -1, 0);
    }
    vector <int> ans(q, 0);
    for (int i = 0; i < q; ++i) {
        int x, y, z; cin >> x >> y >> z;
        if (lx <= x && x <= rx && ly <= y && y <= ry && lz <= z && z <= rz) {
            ans[i] = 1;
        } else {
            cdq.add_event(x, y, z, i, 1);
        }
    }
    cdq.run();
    for (int i = 0; i < q; ++i) {
        if (ans[i] == 1) {
            cout << "OPEN\n";
        } else if (cdq.ans[i]) {
            cout << "CLOSED\n";
        } else {
            cout << "UNKNOWN\n";
        }
    }
}