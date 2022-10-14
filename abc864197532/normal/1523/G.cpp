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
const int mod = 1e9 + 7, N = 50005, logC = 30, K = 450;

struct DS {
    set <pii> s;
    void insert(int p, int v) {
        auto it = s.lower_bound({p, -1});
        if (it != s.end() && it->X == p) {
            if (it->Y < v)
                return;
            s.erase(it);
        }
        it = s.lower_bound({p, v});
        if (it != s.begin()) {
            if (prev(it)->Y <= v)
                return;
        }
        vector <pii> era;
        while (it != s.end()) {
            if (v > it->Y)
                break;
            era.pb(*it);
            it++;
        }
        for (pii A : era)
            s.erase(A);
        s.insert({p, v});
    }
    int query(int p) {
        auto it = s.lower_bound({p, 1 << 30});
        if (it == s.begin())
            return 1 << 30;
        return prev(it)->Y;
    }
} bit[N];

void add(int bound, int p, int v) {
    for (int i = bound; i > 0; i -= i & (-i)) {
        bit[i].insert(p, v);
    }
}

int query(int a, int b) {
    int ans = 1 << 30;
    for (int i = a; i < N; i += i & (-i))
        ans = min(bit[i].query(b), ans);
    return ans;
}

vector <pair <pii, int>> range[N];
int ans[N], l[N << 1], r[N << 1];

int solve(int a, int b) {
    if (a == b)
        return 0;
    int p = query(a + 1, b);
    if (p == 1 << 30)
        return 0;
    return r[p] - l[p] + solve(a, l[p]) + solve(r[p], b);
}

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i], --l[i];
        range[r[i] - l[i]].pb(mp(mp(l[i], r[i]), i));
    }
    for (int len = n; len > 0; --len) {
        for (auto A : range[len])
            add(A.X.X + 1, A.X.Y, A.Y);
        ans[len] = solve(0, n);
    }
    for (int len = 1; len <= n; ++len)
        cout << ans[len] << '\n';
}