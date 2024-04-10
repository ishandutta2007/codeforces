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
const int mod = 998244353, N = 1000087, logN = 19, K = 111, M = 1000006, C = 500;

struct MoAlgorithm {
    struct query {
        int l, r, id;
        bool operator < (const query &o) {
            if (l / C == o.l / C)
                return (l / C) & 1 ? r > o.r : r < o.r;
            return l / C < o.l / C;
        }
    };
    int a[N], cnt[N];
    lli ans[N], cur;
    void add(int x) {
        cnt[x]++;
        cur += (cnt[x] * 2 - 1) * x;
    }
    void sub(int x) {
        cur -= (cnt[x] * 2 - 1) * x;
        cnt[x]--;
    }
    vector <query> Q;
    void add_query(int l, int r, int id) {
        // [l, r)
        Q.push_back({l, r, id});
    }
    void run() {
        sort(all(Q));
        int pl = 0, pr = 0;
        for (query &i : Q) {
            while (pl > i.l)
                add(a[--pl]);
            while (pr < i.r)
                add(a[pr++]);
            while (pl < i.l)
                sub(a[pl++]);
            while (pr > i.r)
                sub(a[--pr]);
            ans[i.id] = cur;
        }
    }
} solver;
 
int main () {
    owo;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> solver.a[i];
    for (int i = 0, l, r; i < q; ++i)
        cin >> l >> r, --l, solver.add_query(l, r, i);
    solver.run();
    for (int i = 0; i < q; ++i) {
        cout << solver.ans[i] << '\n';
    }
}