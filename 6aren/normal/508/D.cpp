#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; };
string to_string(const char *s) { return to_string((string) s); };
string to_string(bool b) { return (b ? "true" : "false"); };
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template<typename A>
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
void debug_out() { cerr << endl; };
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

struct EulerianGraph {
    vector<vector<pair<int, int>>> a;
    int num_edges;
    vector<int> out, in;

    EulerianGraph(int n) {
        a.resize(n);
        num_edges = 0;
        out.resize(n, 0);
        in.resize(n, 0);
    }

    void addEdge(int u, int v) {
        debug(u, v);
        a[u].emplace_back(v, num_edges++);
        out[u]++;
        in[v]++;
    }

    bool check_eulerian() {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (abs(in[i] - out[i]) == 1) cnt++;
            else if (in[i] != out[i]) return false;
        }
        return cnt < 3;
    }

    vector<int> get_eulerian_path() {
        vector<int> path, s;
        vector<bool> was(num_edges);

        if (!check_eulerian()) return path;
        
        int start = 0;
        for (int i = 1; i < a.size(); i++) {
            if (out[i] - in[i] == 1) start = i;
        }
        s.push_back(start);
        while (!s.empty()) {
            int u = s.back();
            bool found = false;
            while (!a[u].empty()) {
                int v = a[u].back().first;
                int e = a[u].back().second;
                a[u].pop_back();
                if (was[e]) continue;
                was[e] = true;
                s.push_back(v);
                found = true;
                break;
            }
            if (!found) {
                path.push_back(u);
                s.pop_back();
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (string &e : s) cin >> e;
    vector<string> vertices;
    for (string &e : s) {
        vertices.push_back(e.substr(0, 2));
        vertices.push_back(e.substr(1, 2));
    }
    sort(vertices.begin(), vertices.end());
    vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());

    debug(vertices);

    EulerianGraph eulerian(vertices.size());

    for (auto &e : s) {
        int u = lower_bound(vertices.begin(), vertices.end(), e.substr(0, 2)) - vertices.begin();
        int v = lower_bound(vertices.begin(), vertices.end(), e.substr(1, 2)) - vertices.begin();
        eulerian.addEdge(u, v);
    }
    vector<int> path = eulerian.get_eulerian_path();
    if (path.size() != n + 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        debug(path);
        string res = vertices[path[0]];
        for (int e : path) {
            debug(vertices[e]);
        }
        for (int i = 1; i < path.size(); i++) {
            res.push_back(vertices[path[i]][1]);
        }
        cout << res << '\n';
    }
}