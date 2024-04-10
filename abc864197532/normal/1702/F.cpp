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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1005, logN = 20, M = 6e6;

struct Dsu {
    vector <int> rt, sz;
    int n, cc;
    Dsu () = default;
    Dsu (int _n) : n(_n), cc(_n) {
        rt.resize(n), iota(rt.begin(), rt.end(), 0);
        sz.assign(n, 1);
    }
    int Find(int v) {
        return rt[v] == v ? v : rt[v] = Find(rt[v]);
    }
    bool Union(int v, int u) {
        u = Find(u), v = Find(v);
        if (u == v)
            return false;
        if (sz[u] > sz[v])
            swap(u, v);
        rt[u] = v;
        sz[v] += sz[u];
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            while (a[i] & 1 ^ 1)
                a[i] >>= 1;
        }
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        sort(all(a));
        priority_queue <int> pq(all(b));
        bool ans = true;
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            if (x < a.back()) {
                ans = false;
                break;
            }
            if (x == a.back())
                a.pop_back();
            else
                pq.push(x >> 1);
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}