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
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
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
const int mod = 998244353, N = 400001, logN = 20, K = 450;

lli curans = 0;

struct DS {
    int cap = 0;
    deque <int> dq;
    void add(int v) {
        if (dq.empty()) {
            assert(cap == 0);
            dq.push_back(v);
        } else if (v <= dq.back()) {
            dq.push_back(v);
        } else if (dq.front() <= v) {
            if (cap)
                curans -= dq[cap - 1];
            dq.push_front(v);
            if (cap)
                curans += v;
        } else {
            assert(false);
        }
    }
    void append() {
        cap++;
        if (dq.size() >= cap)
            curans += dq[cap - 1];
    }
} ds[N];

int dsu[N];

int Find(int x) {
    if (dsu[x] == x)
        return x;
    return dsu[x] = Find(dsu[x]);
}

void merge(int x, int y) {
    x = Find(x), y = Find(y);
    if (ds[x].dq.size() > ds[y].dq.size()) {
        dsu[y] = x;
        for (int i = 0; i < ds[y].cap; ++i)
            curans -= ds[y].dq[i];
        while (!ds[y].dq.empty()) {
            ds[x].add(ds[y].dq.back());
            ds[y].dq.pop_back();
        }
        for (int i = 0; i < ds[y].cap; ++i)
            ds[x].append();
        ds[y].cap = 0;
    } else {
        dsu[x] = y;
        for (int i = 0; i < ds[x].cap; ++i)
            curans -= ds[x].dq[i];
        while (!ds[x].dq.empty()) {
            ds[y].add(ds[x].dq.front());
            ds[x].dq.pop_front();
        }
        for (int i = 0; i < ds[x].cap; ++i)
            ds[y].append();
        ds[x].cap = 0;
    }
}

int main () {
    owo;
    int n, m, q;
    cin >> n >> m >> q;
    iota(dsu, dsu + n + m, 0);
    vector <int> a(n), b(m);
    vector <pii> v(n + m);
    for (int i = 0; i < n; ++i)
        cin >> a[i], v[i] = mp(a[i], 1);
    for (int i = 0; i < m; ++i)
        cin >> b[i], v[i + n] = mp(b[i], 0);
    sort(all(v));
    for (int i = 0; i < n + m; ++i) {
        ds[i].add(v[i].X);
        if (v[i].Y)
            ds[i].append();
    }
    vector <int> d(n + m - 1, 0);
    iota(all(d), 0);
    sort(all(d), [&](int i, int j) {
        return v[i + 1].X - v[i].X < v[j + 1].X - v[j].X;
    });
    vector <int> query(q), p(q);
    for (int i = 0; i < q; ++i)
        cin >> query[i];
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return query[i] < query[j];
    });
    vector <lli> ans(q);
    for (int i = 0, j = 0; i < q; ++i) {
        while (j < n + m - 1 && v[d[j] + 1].X - v[d[j]].X <= query[p[i]]) {
            merge(d[j], d[j] + 1);
            j++;
        }
        ans[p[i]] = curans;
    }
    for (lli i : ans)
        cout << i << endl;
}