#include <bits/stdc++.h>

using namespace std;

using int128 = __int128_t;

#define rep(i, n)         for (int i = 0; i < n; ++i)
#define reps(i, n, s)     for (int i = 0; i < n; i += s)
#define repl(i, l, r)     for (int i = l; i < r; ++i)
#define repsl(i, l, r, s) for (int i = l; i < r; i += s)

#define all(iterable) (iterable).begin(), (iterable).end()

constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template <typename T>
void print_vector(const vector<T>& vec, const string sep = " ", const string end = "\n") {
    int n = vec.size();
    rep(i, n) {
        cout << vec[i];
        if (i < n - 1) cout << sep;
        else cout << end;
    }
}

template <typename T>
void read_vector(vector<T>& a, int begin_index, int length) {
    if (a.size() < begin_index + length) a.resize(begin_index + length);
    while (length --> 0) cin >> a[begin_index++];
}
template <typename T>
void read_vector(vector<T>& a) { read_vector(a, 0, a.size()); }

void solve(int n, int d, int k) {
    
}

int main() {
    int n, d, k;
    cin >> n >> d >> k;
    if (n <= d) {
        cout << "NO\n";
        return 0;
    }
    if (k == 1 and n > 2) {
        cout << "NO\n";
        return 0;
    }
    vector<vector<int>> g(n);
    vector<int> dep(n, -1);
    vector<int> stk;
    int id = 0;
    if (d & 1) {
        int l = d / 2;
        int r = l + 1;
        dep[l] = dep[r] = 0;
        stk.push_back(l);
        stk.push_back(r);
        g[l].push_back(r);
        g[r].push_back(l);
        id += 2;
        for (int i = 1; i <= d / 2; ++i) {
            dep[l - i] = i;
            stk.push_back(l - i);
            g[l - i].push_back(l - i + 1);
            g[l - i + 1].push_back(l - i);
            dep[r + i] = i;
            stk.push_back(r + i);
            g[r + i].push_back(r + i - 1);
            g[r + i - 1].push_back(r + i);
            id += 2;
        }
    } else {
        int m = d / 2;
        dep[m] = 0;
        stk.push_back(m);
        id += 1;
        for (int i = 1; i <= d / 2; ++i) {
            dep[m - i] = i;
            stk.push_back(m - i);
            g[m - i].push_back(m - i + 1);
            g[m - i + 1].push_back(m - i);
            dep[m + i] = i;
            stk.push_back(m + i);
            g[m + i].push_back(m + i - 1);
            g[m + i - 1].push_back(m + i);
            id += 2;
        }
    }
    int max_dep = d / 2;
    while (stk.size() and id < n) {
        int u = stk.back();
        stk.pop_back();
        if (dep[u] == max_dep) continue;
        while (g[u].size() < k and id < n) {
            g[u].push_back(id);
            g[id].push_back(u);
            dep[id] = dep[u] + 1;
            stk.push_back(id);
            ++id;
        }
    }
    if (id < n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                if (j > i) {
                    cout << i + 1 << ' ' << j + 1 << '\n';
                }
            }
        }
    }
    return 0;
}