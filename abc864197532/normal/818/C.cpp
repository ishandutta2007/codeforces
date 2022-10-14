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
const int mod = 1e9 + 7, N = 400005, logN = 18, G = 3;

int main () {
    owo;
    int sz, n, m;
    cin >> sz >> n >> m;
    vector <int> x1(sz), x2(sz), y1(sz), y2(sz);
    for (int i = 0; i < sz; ++i) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        if (x1[i] > x2[i] || y1[i] > y2[i])
            swap(x1[i], x2[i]), swap(y1[i], y2[i]);
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector <int> cntl(sz), cntr(sz), cntu(sz), cntd(sz);
    {
        vector <int> add(m + 1);
        vector <vector <int>> query(m + 1);
        for (int i = 0; i < sz; ++i) {
            add[y1[i]]++;
            query[y2[i]].pb(i);
        }
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            for (int id : query[i]) {
                cntu[id] = cnt - (y1[id] != y2[id]);
            }
            cnt += add[i];
        }
    }
    {
        vector <int> add(m + 1);
        vector <vector <int>> query(m + 1);
        for (int i = 0; i < sz; ++i) {
            add[y2[i]]++;
            query[y1[i]].pb(i);
        }
        int cnt = 0;
        for (int i = m; i; --i) {
            for (int id : query[i]) {
                cntd[id] = cnt - (y1[id] != y2[id]);
            }
            cnt += add[i];
        }
    }
    {
        vector <int> add(n + 1);
        vector <vector <int>> query(n + 1);
        for (int i = 0; i < sz; ++i) {
            add[x1[i]]++;
            query[x2[i]].pb(i);
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int id : query[i]) {
                cntl[id] = cnt - (x1[id] != x2[id]);
            }
            cnt += add[i];
        }
    }
    {
        vector <int> add(n + 1);
        vector <vector <int>> query(n + 1);
        for (int i = 0; i < sz; ++i) {
            add[x2[i]]++;
            query[x1[i]].pb(i);
        }
        int cnt = 0;
        for (int i = n; i; --i) {
            for (int id : query[i]) {
                cntr[id] = cnt - (x1[id] != x2[id]);
            }
            cnt += add[i];
        }
    }
    for (int i = 0; i < sz; ++i) if (cntl[i] == a && cntr[i] == b && cntu[i] == c && cntd[i] == d) {
        cout << i + 1 << '\n';
        return 0;
    }
    cout << -1 << '\n';
}