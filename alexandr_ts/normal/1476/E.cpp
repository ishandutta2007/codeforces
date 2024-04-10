#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ui32 = unsigned int;
constexpr ll INFLL = 1e18;

#define CHECK_IMPL1(cond)              \
if (!(cond)) {                         \
    DEBUG("expected cond: " << #cond); \
    assert(cond);                      \
}

#define CHECK_IMPL2(cond, message)                                            \
if (!(cond)) {                                                                \
    DEBUG("expected cond: " << #cond << " failed with message: " << message); \
    assert(cond);                                                             \
}
#define CHECK_IMPL(_1, _2, NAME, ...) NAME
#define CHECK(...) CHECK_IMPL(__VA_ARGS__, CHECK_IMPL2, CHECK_IMPL1, CHECK_IMPL0)(__VA_ARGS__)

#ifdef __SANYA__
#define DEBUG(message) std::cerr << message << std::endl;
#else
#define DEBUG(message)
#endif

bool match(const string& s, const string& pat) {
    assert(s.size() == pat.size());
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != pat[i] && pat[i] != '_') {
            return false;
        }
    }
    return true;
}

const int N = 81 * 10000 + 100;

int encode(const string& pat) {
    int code = 0;
    for (int i = 0; i < pat.size(); ++i) {
        int val;
        if (pat[i] == '_') {
            val = 1;
        } else {
            val = pat[i] - 'a' + 2;
        }
        code = code * 28 + val;
    }
    return code;
}

vector<int> g[N];

vector<int> all_pats(const string& s) {
    int n = s.size();
    vector<int> result;
    for (int i = 0; i < (1 << n); ++i) {
        string t = s;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                t[j] = '_';
            }
        }
        result.push_back(encode(t));
    }
    return result;
}

bool used[N];
vector<int> path;
int tin[N];
int tout[N];
int tim = 1;

bool dfs(int v) {
    tin[v] = tim++;
    bool ok = true;
    for (auto u: g[v]) {
        if (tin[u] && tout[u] == 0) {
            ok = false;
            break;
        }
        if (!tin[u]) {
            ok &= dfs(u);
        }
    }
    tout[v] = tim++;
    path.push_back(v);
    return ok;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> pat(n);
    for (int i = 0; i < n; ++i) {
        cin >> pat[i];
    }
    vector<int> p(m);
    vector<string> s(m);
    for (int i = 0; i < m; ++i) {
        cin >> s[i] >> p[i];
        p[i]--;
    }
    for (int i = 0; i < m; ++i) {
        if (!match(s[i], pat[p[i]])) {
            cout << "NO" << endl;
            return;
        }
        auto all_codes = all_pats(s[i]);
        int code = encode(pat[p[i]]);
        for (auto u: all_codes) {
            if (u != code) {
                g[code].push_back(u);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            bool rez = dfs(i);
            if (!rez) {
                cout << "NO\n";
                return;
            }
        }
    }
    reverse(path.begin(), path.end());

    vector<int> pos(path.size());
    for (int i = 0; i < path.size(); ++i) {
        pos[path[i]] = i;
    }
    vector<int> seq(n);
    set<int> dif;
    for (int i = 0; i < n; ++i) {
        int code = encode(pat[i]);
        seq[i] = pos[code];
        dif.insert(seq[i]);
    }

    map<int, int> squeeze;
    for (auto x: dif){
        int sz = squeeze.size();
        squeeze[x] = sz;
    }

    vector<int> answer(n);
    for (int i = 0; i < seq.size(); ++i) {
        seq[i] = squeeze[seq[i]];
        answer[seq[i]] = i;
    }
    cout << "YES\n";

    for (auto x: answer) {
        cout << x + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef __SANYA__
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    solve();

    return 0;
}