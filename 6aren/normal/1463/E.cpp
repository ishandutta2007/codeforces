#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n), h(n), gg(n);
    vector<int> done(n, 0), deg(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        if (p[i] >= 0) deg[p[i]]++, gg[p[i]].push_back(i);
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        h[y].push_back(x);
    }
    vector<int> iq(n), in(n, -1);
    vector<vector<int>> comps(n);
    for (int i = 0; i < n; i++) {
        if (max(g[i].size(), h[i].size()) > 1) {
            return cout << 0 << '\n', 0;
        } 
    }
    vector<int> degComp(n);
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1 && h[i].size() == 0) {
            int cur = i;
            while (g[cur].size() == 1) {
                comps[i].push_back(cur);
                cur = g[cur][0];
            }
            comps[i].push_back(cur);
            for (int e : comps[i]) {
                iq[e] = 1; 
                in[e] = i;
            } 
            for (int e : comps[i]) {
                for (int v : gg[e]) {
                    if (in[v] != i) {
                        degComp[i]++;
                    }
                }
            }
        }
    }

    vector<int> res;
    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (iq[i] == 1 && degComp[in[i]] == 0) {
            for (int j = comps[in[i]].size() - 1; j >= 0; j--) {
                q.push_back(comps[in[i]][j]);
            }
            degComp[in[i]] = 1e9;
        } else if (deg[i] == 0 && iq[i] == 0) {
            q.push_back(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        res.push_back(u);
        int par = p[u];
        if (par == -1) break;
        deg[par]--;
        if (iq[par]) {
            degComp[in[par]]--;
            if (degComp[in[par]] == 0) {
                for (int j = comps[in[par]].size() - 1; j >= 0; j--) {
                    q.push_back(comps[in[par]][j]);
                }
                degComp[in[par]] = 1e9;
            }
        } else if (deg[par] == 0) {
            q.push_back(par);
        }
    }

    if (res.size() != n) {
        cout << 0 << '\n';
        return 0;
    }

    reverse(res.begin(), res.end());
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[res[i]] = i;
    }

    debug(res);

    for (int i = 0; i < n; i++) {
        int  par = p[i];
        if (par == -1) continue;
        if (pos[par] > pos[i]) return cout << 0 << '\n', 0;
        if (g[i].size() > 0) {
            if (pos[g[i][0]] - pos[i] != 1) return cout << 0 << '\n', 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] + 1 << ' ';
    }
    cout << '\n';

    return 0;
}