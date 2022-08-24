#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

const int N = 4007, K = 107, inf = 1e9, SZ = 42424243;
int s[N];

inline int next(int x) {
    return (x == SZ - 1 ? 0 : x + 1);
}

struct super_hash_map {
    pair <int, int> elems[SZ];
    bool used[SZ];
    void set(int x, int y) {
        int cur = x % SZ;
        while (used[cur]) {
            cur = next(cur);
        }
        used[cur] = 1;
        elems[cur] = {x, y};
    }
    int get(int x) {
        int cur = x % SZ;
        while (used[cur]) {
            if (elems[cur].first == x) {
                return elems[cur].second;
            }
            cur = next(cur);
        }
        return 0;
    }
    bool count(int x) {
        int cur = x % SZ;
        while (used[cur]) {
            if (elems[cur].first == x) {
                return 1;
            }
            cur = next(cur);
        }
        return 0;
    }
};

struct hash_map {
    vector <pair <int, int> > elems[SZ];
    void set(int x, int y) {
        elems[x % SZ].push_back({x, y});
    }
    int get(int x) {
        for (auto c : elems[x % SZ]) {
            if (c.first == x) {
                return c.second;
            }
        }
        return 0;
    }
    bool count(int x) {
        for (auto c : elems[x % SZ]) {
            if (c.first == x) {
                return 1;
            }
        }
        return 0;
    }
};

super_hash_map dp;

int calc(int l, int r, int k, int t) {
    int d = l * N * K * 2 + r * K * 2 + k * 2 + t;
    int res = 0;
    if (dp.count(d)) return dp.get(d);
    if (t) {
        res = -inf;
        if (k <= r - l + 1) {
            res = max(res, calc(l + k, r, k, t ^ 1) + (s[l + k - 1] - s[l - 1]));
        }
        k++;
        if (k <= r - l + 1) {
            res = max(res, calc(l + k, r, k, t ^ 1) + (s[l + k - 1] - s[l - 1]));
        }
        if (res == -inf) res = 0;
    } else {
        res = inf;
        if (k <= r - l + 1) {
            res = min(res, calc(l, r - k, k, t ^ 1) - (s[r] - s[r - k]));
        }
        k++;
        if (k <= r - l + 1) {
            res = min(res, calc(l, r - k, k, t ^ 1) - (s[r] - s[r - k]));
        }
        if (res == inf) res = 0;
    }
    dp.set(d, res);
    return res;
}


int main() {
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    cout << calc(1, n, 1, 1) << '\n';
}