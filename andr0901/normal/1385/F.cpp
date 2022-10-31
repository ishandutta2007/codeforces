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

void solve() {
    int n, k;
    cin >> n >> k;
    vector <set <int>> gr(n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].insert(u), gr[u].insert(v);
    }
    auto is_leaf = [&](int v) {
        return gr[v].size() == 1;
    };
    vector <int> cnt(n);
    vector <bool> used(n);
    set <int> good;
    forn (i, 0, n) {
        for (int j : gr[i])
            cnt[i] += is_leaf(j);
        if (cnt[i] % k == 0 && cnt[i] > 0) {
            //used[i] = true;
            good.insert(i);
        }
    }
    int ans = 0;
    while (!good.empty()) {
        int v = *good.begin();
        good.erase(good.begin());
        //used[v] = true;
        vector <int> leaves;
        for (int u : gr[v])
            if (is_leaf(u))
                leaves.pb(u);
        for (int u : leaves) {
            gr[v].erase(u);
            gr[u].clear();
        }
        ans += sz(leaves) / k;
        if (is_leaf(v)) {
            for (int u : gr[v]) {
                cnt[u]++;
                if (good.find(u) != good.end() &&
                    cnt[u] % k)
                    good.erase(u);
                if (cnt[u] > 0 && cnt[u] % k == 0) {
                    good.insert(u);
                }
            }
        }
    }
    forn (i, 0, n) {
        int cur = 0;
        for (int j : gr[i])
            cur += is_leaf(j);
        ans += cur / k;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}