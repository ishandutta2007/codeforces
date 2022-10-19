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


const int maxN = 100005;

int n, m;
int timeDfs = 0, scc = 0;
int low[maxN], num[maxN];
bool deleted[maxN];
vector <int> g[maxN];
stack <int> st;
int comp[maxN], cnt[maxN];

void dfs(int u) {
    num[u] = low[u] = ++timeDfs;
    st.push(u);
    for (int v : g[u]) {
    	if (deleted[v]) continue;
        if (!num[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        scc++;
        int v;
        do {
            v = st.top(); 
            comp[v] = scc;
            st.pop();
            deleted[v] = true;
        }
        while (v != u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;

    while (tt--) {
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        vector<int> foo(n);
        for (int i = 0; i < n; i++) {
            foo[i] = i + 1;
        }
        sort(foo.begin(), foo.end(), [&](int l, int r) {
            return a[l] < a[r];
        });
        for (int i = 1; i < n; i++) {
            g[foo[i]].push_back(foo[i - 1]);
        }
        sort(foo.begin(), foo.end(), [&](int l, int r) {
            return b[l] < b[r];
        });
        for (int i = 1; i < n; i++) {
            g[foo[i]].push_back(foo[i - 1]);
        }
        for (int i = 1; i <= n; i++) {
            if (!num[i]) dfs(i);
        }
        for (int i = 1; i <= n; i++) {
            for (int e : g[i]) if (comp[i] != comp[e]) cnt[comp[e]]++;
        }
        for (int i = 1; i <= n; i++) {
            cout << (cnt[comp[i]] == 0 ? 1 : 0);
        }
        cout << '\n';
        for (int i = 1; i <= n; i++) {
            timeDfs = 0, scc = 0;
            low[i] = num[i] = deleted[i] = 0;
            g[i].clear();
            comp[i] = cnt[i] = 0;
        }
    }

    return 0;
}