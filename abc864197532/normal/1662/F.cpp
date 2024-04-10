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
const int mod = 998244353, N = 1600087, logN = 19, K = 111, M = 1000006, C = 500;

vector <int> p;
vector <int> res;

struct Seg {
    int l, r, m, rmx, lmn;
    Seg* ch[2];
    Seg (int _l, int _r, int s) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, s);
            ch[1] = new Seg(m, r, s);
            pull();
        } else {
            if (l == s)
                lmn = 1 << 30, rmx = -1 << 30;
            else
                lmn = l - p[l], rmx = l + p[l] + 1;
        }
    }
    void pull() {lmn = min(ch[0]->lmn, ch[1]->lmn), rmx = max(ch[0]->rmx, ch[1]->rmx);}
    void query(int a, int b, int id, bool tag) {
        if (a >= b)
            return;
        if (a <= l && r <= b) {
            if (r - l == 1) {
                if (tag) {
                    if (rmx > id)
                        rmx = -1 << 30, lmn = 1 << 30, res.pb(l);
                } else {
                    if (lmn <= id)
                        rmx = -1 << 30, lmn = 1 << 30, res.pb(l);
                }
            } else {
                for (auto &i : ch) {
                    if (tag) {
                        if (i->rmx > id) 
                            i->query(a, b, id, tag);
                    } else {
                        if (i->lmn <= id)
                            i->query(a, b, id, tag);
                    }
                }
                pull();
            }
        } else {
            if (a < m)
                ch[0]->query(a, b, id, tag);
            if (m < b)
                ch[1]->query(a, b, id, tag);
            pull();
        }
    }
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, s, t;
        cin >> n >> s >> t, --s, --t;
        p.assign(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        Seg root(0, n, s);
        queue <int> q;
        q.push(s);
        vector <int> dis(n, -1);
        dis[s] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            int l = max(v - p[v], 0), r = min(v + p[v] + 1, n);
            res.clear();
            root.query(l, v, v, true);
            root.query(v + 1, r, v, false);
            for (int u : res)
                dis[u] = dis[v] + 1, q.push(u);
        }
        cout << dis[t] << '\n';
    }
}