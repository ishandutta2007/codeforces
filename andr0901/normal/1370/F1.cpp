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

vector <vector <int>> gr;

pair <int, int> ask(vector <int>& a) {
    cout << "? " << a.size() << " ";
    for (int i : a)
        cout << i + 1 << " ";
    cout << endl;
    int v, s;
    cin >> v >> s, --v;
    return {v, s};
}

vector <int> dst;

void dfs_dst(int v, int p = -1) {
    if (p == -1)
        dst[v] = 0;
    else
        dst[v] = dst[p] + 1;
    for (int u : gr[v])
        if (u != p)
            dfs_dst(u, v);
}

vector <int> suspects;

void dfs_lst(int v, int p, int needed_d, int cur_d = 0) {
    if (cur_d == needed_d)
        suspects.pb(v);
    for (int u : gr[v])
        if (u != p)
            dfs_lst(u, v, needed_d, cur_d + 1);
}

void solve() {
    int n;
    cin >> n;
    gr = vector <vector <int>> (n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    vector <int> everything;
    forn (i, 0, n)
        everything.pb(i);
    auto [root, d] = ask(everything);
    dst = vector <int> (n);
    dfs_dst(root);
    vector <vector <int>> levels(n);
    forn (i, 0, n)
        levels[dst[i]].pb(i);
    int lst_succesful = -1;
    auto check = [&](int m) {
        if (levels[m].empty())
            return false;
        auto [ans_v, ans_d] = ask(levels[m]);
        if (ans_d == d)
            lst_succesful = ans_v;
        return ans_d == d;
    };
    int mx_d = *max_element(all(dst));
    int l = max(0, d / 2 - 1), r = d + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (check(m))
            l = m;
        else
            r = m;
    }
    suspects.clear();
    dfs_lst(lst_succesful, -1, d);
    int ans = ask(suspects).fs;
    cout << "! " << lst_succesful + 1 << " " << ans + 1 << endl;
    string verdict;
    cin >> verdict;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}