#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename A> ostream& operator<<(ostream &os, const vector<A> &vt) {
    os << '[';
    for (size_t i = 0; i + 1 < vt.size(); i++) os << vt[i] << ", ";
    if (!vt.empty()) os << vt.back();
    return os << ']';
}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef GAREN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void run_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> res(n, vector<int>(n, -1));
    vector<int> foo;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') for (int j = 0; j < n; j++) {
            res[i][j] = 2;
            res[j][i] = 2;
        } else foo.push_back(i);
    }
    if (foo.size() == 1 || foo.size() == 2) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < foo.size(); i++) {
        int u = foo[i];
        int v = foo[(i + 1) % foo.size()];
        res[u][v] = 1;
        res[v][u] = 0;
    }
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
        if (res[i][j] == -1) res[i][j] = 1, res[j][i] = 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << 'X';
            else if (res[i][j] == 1) cout << '+';
            else if (res[i][j] == 2) cout << '=';
            else cout << '-';
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    cin >> tests;
    while (tests--) run_case();
    return 0;
}