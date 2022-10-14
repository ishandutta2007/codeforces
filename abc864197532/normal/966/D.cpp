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
const int mod = 1e9 + 7, N = 3e5 + 7, logN = 18;

vector <int> adj[N];

void out(vector <int> ans) {
    cout << ans.size() - 1 << '\n';
    for (int &i : ans)
        i++;
    printv(all(ans));
    exit(0);
}

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0; i < n; ++i)
        sort(rall(adj[i]));
    // bfs source 1
    {
        queue <int> q;
        vector <int> dis(n, -1), rt(n, -1);
        q.push(0), dis[0] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : adj[v]) if (dis[u] == -1)
                dis[u] = dis[v] + 1, rt[u] = v, q.push(u);
        }
        if (dis[n - 1] != -1 && dis[n - 1] <= 4) {
            vector <int> ans;
            int now = n - 1;
            while (now != -1)
                ans.pb(now), now = rt[now];
            reverse(all(ans));
            out(ans);
        }
        for (int i = 1; i < n; ++i) if (dis[i] == 2) {
            vector <int> ans = {0, rt[i], i, 0, n - 1};
            out(ans);
        }
    }
    // delete point 1
    adj[0].clear();
    for (int i = 1; i < n; ++i) if (!adj[i].empty() && adj[i].back() == 0)
        adj[i].pop_back();
    vector <int> dis(n, -1), rt(n, -1);
    for (int s = 1; s < n; ++s) if (dis[s] == -1) {
        queue <int> q;
        q.push(s), dis[s] = 0;
        vector <int> cc;
        bool fail = false;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            cc.pb(v);
            if (v == n - 1)
                fail = true;
            for (int u : adj[v]) if (dis[u] == -1)
                dis[u] = dis[v] + 1, rt[u] = v, q.push(u);
        }
        if (fail)
            continue;
        for (int i : cc) if (dis[i] == 2) {
            vector <int> ans = {0, 1, rt[i], i, 1, n - 1};
            out(ans);
        }
        for (int i : cc) if (adj[i].size() + 1 < cc.size()) {
            set <int> S(all(cc));
            S.erase(i);
            for (int j : adj[i]) if (S.count(j))
                S.erase(j);
            assert(!S.empty());
            int x = *S.begin();
            vector <int> ans = {0, i, s, x, i, n - 1};
            out(ans);
        }
    }
    cout << -1 << '\n';
}