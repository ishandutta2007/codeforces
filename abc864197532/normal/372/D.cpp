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
const int mod = 998244353, N = 1e5 + 87, logN = 18, K = 111;

vector <int> adj[N];
int in[N], out[N], _t, dep[N], jump[N][logN];

void dfs(int v, int pa) {
    in[v] = _t++;
    jump[v][0] = pa;
    for (int i = 1; i < logN; ++i) {
        int k = jump[v][i - 1];
        jump[v][i] = k == -1 ? -1 : jump[k][i - 1];
    }
    for (int u : adj[v]) if (u != pa) {
        dep[u] = dep[v] + 1;
        dfs(u, v);
    }
    out[v] = _t++;
}

bool anc(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
    if (anc(u, v))
        return u;
    if (anc(v, u))
        return v;
    for (int i = logN - 1; ~i; --i) {
        int k = jump[u][i];
        if (k != -1 && !anc(k, v))
            u = k;
    }
    return jump[u][0];
}

int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main () {
    owo;
    int n, k;
    cin >> n >> k;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1);
    int ans = 0, sum = 0;
    set <pii> s;
    auto add = [&](int v) {
        int l, r;
        if (s.empty()) {
            s.insert({in[v], v});
            return;
        } else if (s.size() == 1) {
            l = r = s.begin()->Y;
        } else {
            auto it = s.lower_bound({in[v], v});
            if (it == s.end()) {
                r = s.begin()->Y;
            } else {
                r = it->Y;
            }
            if (it == s.begin()) {
                l = prev(s.end())->Y;
            } else {
                l = prev(it)->Y;
            }
        }
        sum -= dis(l, r);
        sum += dis(l, v) + dis(v, r);
        s.insert({in[v], v});
    };
    auto del = [&](int v) {
        s.erase({in[v], v});
        int l, r;
        if (s.empty()) {
            return;
        } else if (s.size() == 1) {
            l = r = s.begin()->Y;
        } else if (!s.empty()) {
            auto it = s.lower_bound({in[v], v});
            if (it == s.end()) {
                r = s.begin()->Y;
            } else {
                r = it->Y;
            }
            if (it == s.begin()) {
                l = prev(s.end())->Y;
            } else {
                l = prev(it)->Y;
            }
        }
        sum += dis(l, r);
        sum -= dis(l, v) + dis(v, r);
    };
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n) {
            add(j);
            if (sum + 2 > 2 * k) {
                del(j);
                break;
            }
            j++;
        }
        ans = max(ans, j - i);
        del(i);
    }
    cout << ans << endl;
}