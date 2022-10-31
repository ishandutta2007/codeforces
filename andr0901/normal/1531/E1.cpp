//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

string s;
int idx;
vector<vector<int>> gr;

vector<int> a;

void rec(int l, int r) {
    if (r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;
    rec(l, m);
    rec(m, r);
    int i = l, j = m;
    vector<int> b;
    while (i < m && j < r) {
        if (idx >= s.size()) {
            return;
        }
        if (s[idx] == '0') {
            gr[a[i]].pb(a[j]);
            b.pb(a[i]);
            ++i;
        } else {
            gr[a[j]].pb(a[i]);
            b.pb(a[j]);
            ++j;
        }
        ++idx;
    }
    while (i < m) {
        b.pb(a[i]);
        ++i;
    }
    while (j < r) {
        b.pb(a[j]);
        ++j;
    }
    for (int i = l, j = 0; i < r; ++i, ++j) {
        a[i] = b[j];
    }
}

bool solve(int n) {
    idx = 0;
    gr = vector<vector<int>> (n);
    a = vector<int> (n);
    iota(all(a), 0);
    rec(0, n);
    cerr << idx << "\n";
    return idx == s.size();
}

vector<int> ord;

vector<bool> used;

void dfs(int v) {
    used[v] = true;
    for (int u : gr[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
    ord.pb(v);
}

void condensate(int n) {
    used = vector<bool> (n);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(all(ord));
}

void rev(vector<int>& p) {
    vector<int> ans(p.size());
    for (int i = 0; i < p.size(); ++i) {
        ans[p[i]] = i;
    }
    p = ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    int n = 16;
    solve(n);
    condensate(n);
    rev(ord);
    cout << n << "\n";
    for (int x : ord) {
        cout << x + 1 << " ";
    }
    cerr << ord << "\n";
    return 0;
}