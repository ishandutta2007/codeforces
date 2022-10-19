#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;
#define int long long
const int INF = 1e9;

struct dsu {
    int n;
    vector <int> p, sz;

    dsu(int n) : n(n) {
        p.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int parent(int v) {
        if (v == p[v]) return v;
        p[v] = parent(p[v]);
        return p[v];
    }

    inline bool unite(int a, int b) {
        a = parent(a);
        b = parent(b);
        if (a == b) return false;
        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
        return true;
    }
};

void solve1() {
    int n;
    cin >> n;
    n *= 2;
    string s;
    cin >> s;
    vector <int> p(n + 1);
    vector <vector <int>> all(2 * n + 2);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i];
        if (s[i] == '(') p[i + 1]++;
        else p[i + 1]--;
    }
    for (int i = 0; i <= n; ++i) all[p[i] + n].push_back(i);
    vector <int> bl_less(n + 1, n + 1), st;
    for (int i = 0; i <= n; ++i) {
        while (!st.empty() && p[st.back()] > p[i]) {
            bl_less[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    int ans = n;
    dsu now(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') continue;
        int r = bl_less[i];
        auto it = lower_bound(all[p[i] + n].begin(), all[p[i] + n].end(), r);
        it--;
        while (*it > i) {
            if (now.unite(i, *it - 1)) {
                ans--;
            } else {
                break;
            }
            it--;
        }
    }
    cout << ans << "\n";
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        cin >> t;
        while (t--) {
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */