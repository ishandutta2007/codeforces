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
const int mod = 998244353, N = 200005, logN = 20, K = 111;

struct edge {
    int to, idx;
};

vector <edge> adj[N];
bool used[N];
vector <int> path;

void dfs(int v) {
    while (!adj[v].empty()) {
        auto e = adj[v].back(); adj[v].pop_back();
        if (used[e.idx])
            continue;
        used[e.idx] = used[e.idx ^ 1] = true;
        dfs(e.to);
    }
    path.pb(v);
}

int main () {
    owo;
    int n;
    cin >> n;
    vector <vector <int>> a(n);
    vector <string> ans(n);
    vector <int> v;
    for (int i = 0, sz; i < n; ++i) {
        cin >> sz, a[i].resize(sz), ans[i].resize(sz, '.');
        for (int &j : a[i])
            cin >> j, v.pb(j);
    }
    sort(all(v)), v.resize(unique(all(v)) - v.begin());
    for (auto &A : a) for (int &i : A)
        i = lower_bound(all(v), i) - v.begin();
    vector <int> is(v.size(), -1);
    int _t = 0;
    vector <int> cnt(v.size(), 0);
    map <pii, vector <pair <pii, pii>>> res;
    for (int i = 0; i < n; ++i) {
        int sz = a[i].size();
        for (int j = 0; j < sz; ++j) {
            int x = a[i][j];
            cnt[x] ^= 1;
            if (is[x] == -1) {
                is[x] = j;
            } else {
                ans[i][is[x]] = 'L', ans[i][j] = 'R';
                is[x] = -1;
            }
        }
        int l = -1;
        for (int j = 0; j < sz; ++j) if (ans[i][j] == '.') {
            if (l == -1) {
                l = j;
            } else {
                adj[a[i][l]].pb({a[i][j], _t++});
                adj[a[i][j]].pb({a[i][l], _t++});
                res[mp(a[i][l], a[i][j])].eb(mp(i, l), mp(i, j));
                res[mp(a[i][j], a[i][l])].eb(mp(i, j), mp(i, l));
                l = -1;
            }
            is[a[i][j]] = -1;
        }
    }
    if (count(all(cnt), 1))
        return cout << "NO\n", 0;
    for (int i = 0; i < N; ++i) if (!adj[i].empty())
        dfs(i);
    for (int i = 1; i < path.size(); ++i) {
        int from = path[i - 1], to = path[i];
        while (!res[mp(from, to)].empty()) {
            int x1, y1, x2, y2;
            tie(x1, y1) = res[mp(from, to)].back().X;
            tie(x2, y2) = res[mp(from, to)].back().Y;
            res[mp(from, to)].pop_back();
            if (ans[x1][y1] != '.')
                continue;
            ans[x1][y1] = 'L', ans[x2][y2] = 'R';
            break;
        }
    }
    cout << "YES\n";
    for (string s : ans) {
        cout << s << endl;
    }
}