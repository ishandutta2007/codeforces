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
const int mod = 998244353, N = 600001, logN = 18, B = 550;

int x[N], y[N], dep[N];
vector <int> adj[N];
vector <pii> res;
bool vis[N], vis_edge[N];

bool dfs(int v, int pa, int _id = -1) {
    vis[v] = true;
    vector <int> could_pair;
    for (int id : adj[v]) {
        int u = x[id] ^ y[id] ^ v;
        if (u == pa || vis_edge[id])
            continue;
        vis_edge[id] = true;
        if (vis[u]) {
            could_pair.pb(id);
        } else {
            if (dfs(u, v, id)) could_pair.pb(id);
        }
    }
    while (could_pair.size() >= 2) {
        int x = could_pair.back(); could_pair.pop_back();
        int y = could_pair.back(); could_pair.pop_back();
        res.eb(x, y);
    }
    if (!could_pair.empty()) {
        res.eb(could_pair.back(), _id);
        could_pair.pop_back();
        return false;
    }
    return true;
}

bool vis2[N];
int E;
vector <int> E_id;

void dfs1(int v) {
    vis2[v] = true;
    E += adj[v].size();
    for (int id : adj[v]) {
        E_id.pb(id);
        int u = x[id] ^ y[id] ^ v;
        if (vis2[u])
            continue;
        dfs1(u);
    }
}

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> cnt(2 * n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        if (x[i] > y[i])
            swap(x[i], y[i]);
        adj[x[i]].pb(i), adj[y[i]].pb(i);
    }
    int t = 0;
    vv <int> ans(2, n, -1);
    string s0(n, ' '), s1(n, ' '), t0(n, ' '), t1(n, ' ');
    for (int i = 1; i <= n * 2; ++i) if (!vis[i]) {
        dfs1(i);
        E >>= 1;
        if (!E)
            continue;
        if (E == 1) {
            cout << "-1\n";
            return 0;
        }
        E = 0, E_id.clear();
        dfs(i, -1, -1);
        int del = -1;
        if (res.back().Y == -1) {
            del = res.back().X, res.pop_back();
        }
        if (del != -1) {
            int pos = -1;
            for (int i = 0; i < res.size(); ++i) {
                int a, b; tie(a, b) = res[i];
                if (x[a] == x[del] || y[a] == y[del] || x[a] == y[del] || y[a] == x[del])
                    pos = i;
                else if (x[b] == x[del] || y[b] == y[del] || x[b] == y[del] || y[b] == x[del])
                    pos = i;
                if (pos != -1) {
                    break;
                }
            }
            int a, b; tie(a, b) = res[pos];
            assert(pos != -1);
            res.erase(res.begin() + pos);
            vector <pii> now;
            now.eb(x[del], y[del]);
            now.eb(x[a], y[a]);
            now.eb(x[b], y[b]);
            sort(all(now));
            bool tans = false;
            do {
                for (int s = 0; s < 8; ++s) {
                    vector <pii> nxt = now;
                    for (int i = 0; i < 3; ++i) if (s >> i & 1)
                        swap(nxt[i].X, nxt[i].Y);
                    vector <pii> res;
                    res.eb(nxt[0].X, nxt[1].X);
                    res.eb(nxt[0].Y, nxt[2].X);
                    res.eb(nxt[1].Y, nxt[2].Y);
                    for (auto &[x, y] : res) if (x > y)
                        swap(x, y);
                    sort(all(res));
                    if (res == now) {
                        ans[0][t] = nxt[0].X, ans[1][t] = nxt[0].Y;
                        ans[0][t + 1] = nxt[1].X, ans[0][t + 2] = nxt[1].Y;
                        ans[1][t + 1] = nxt[2].X, ans[1][t + 2] = nxt[2].Y;
                        tans = true;
                        break;
                    }
                }
                if (tans)
                    break;
            } while (next_permutation(all(now)));
            s0[t] = 'U', s1[t] = 'D';
            s0[t + 1] = 'L', s0[t + 2] = 'R';
            s1[t + 1] = 'L', s1[t + 2] = 'R';
            t0[t] = 'L', t0[t + 1] = 'R';
            t1[t] = 'L', t1[t + 1] = 'R';
            t0[t + 2] = 'U', t1[t + 2] = 'D';
            t += 3;
        }
        for (auto [a, b] : res) {
            if (x[a] != y[b] && x[b] != y[a])
                swap(x[a], y[a]);
            assert(x[a] == y[b] || x[b] == y[a]);
            s0[t] = 'U', s1[t] = 'D', s0[t + 1] = 'U', s1[t + 1] = 'D';
            t0[t] = 'L', t1[t] = 'L', t0[t + 1] = 'R', t1[t + 1] = 'R';
            ans[0][t] = x[a], ans[1][t] = y[a];
            ans[0][t + 1] = x[b], ans[1][t + 1] = y[b];
            t += 2;
        }
        res.clear();
    }
    cout << 2 << ' ' << n << endl;
    printv(all(ans[0])), printv(all(ans[1]));
    cout << s0 << endl << s1 << endl;
    cout << t0 << endl << t1 << endl;
}