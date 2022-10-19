#include <bits/stdc++.h>

using namespace std;
#define ll long long
inline int min(const int &a, const int &b) {
    if (a < b) return a;
    else return b;
}

const ll mod = 1e9 + 7;

inline ll solve1(int n) {
    ll fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact = (fact * i) % mod;
    }
    ll st_2 = 1;
    for (int i = 0; i < n - 1; ++i) {
        st_2 = (st_2 * 2) % mod;
    }
    return ((fact - st_2) % mod + mod) % mod;
}

inline void solve2(int n) {
    vector <int> a(n);
    for (int i = 1; i <= n; ++i) a[i - 1] = i;
    int fact = 1;
    for (int i = 1; i <= n; ++i) fact *= i;
    for (int _ = 0; _ < fact; ++_) {
        int kol = 0;
        vector <vector <int>> g(n);
        vector <bool> used(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (a[j] > a[i]) {
                    ++kol;
                    break;
                }
            }
            for (int j = i + 1; j < n; ++j) {
                if (a[j] > a[i]) {
                    ++kol;
                    break;
                }
            }
        }

        function<bool(int)> dfs = [&](int v) {
            used[v] = true;
            for (int i : g[v]) {
                if (used[i]) return true;
                if (dfs(i)) return true;
            }
            return false;
        };

        if (kol < n) {
            for (int i : a) cout << i << " ";
            cout << "\n";
        }
        next_permutation(a.begin(), a.end());
    }
}

signed main() {
    srand(time(0));
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int n;
        cin >> n;
        cout << solve1(n);
    }
    else {

    }
}