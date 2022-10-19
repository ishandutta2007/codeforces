#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cassert>
#include <array>

using namespace std;
#define int long long
const int INF = 1e9;

int cur_x;

inline bool cmp(const array <int, 3>& a, const array <int, 3>& b) {
    int va = abs(cur_x - a[0]), vb = abs(cur_x - b[0]);
    if (va != vb) return va < vb;
    return a[0] > b[0];
}

vector <int> pr, sz;

int parent(int v) {
    if (pr[v] == v) return v;
    pr[v] = parent(pr[v]);
    return pr[v];
}

inline bool unite(int a, int b) {
    a = parent(a);
    b = parent(b);
    if (a == b) return false;
    if (sz[a] > sz[b]) swap(a, b);
    pr[a] = b;
    sz[b] += sz[a];
    return true;
}

inline int solve1(int n, int m, int p, int k, int a, int b, int c, vector <array <int, 3>> all, vector <int> qq) {
    sort(all.begin(), all.end());
    vector <int> all_x = {0, INF};
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            int s = all[i][0] + all[j][0];
            if (s % 2 == 0) all_x.push_back(s / 2);
            else {
              //  all_x.push_back(s / 2);
                all_x.push_back((s + 1) / 2);
            }
        }
    }
    sort(all_x.begin(), all_x.end());
    all_x.resize(unique(all_x.begin(), all_x.end()) - all_x.begin());
    pr.assign(n, 0);
    sz.assign(n, 1);
    for (int i = 0; i < n; ++i) pr[i] = i;
    int ln = (int)all_x.size();
    vector <int> sum1(ln), sum2(ln), cnt(ln);
    for (int i = 0; i < ln - 1; ++i) {
        cur_x = all_x[i];
        sort(all.begin(), all.end(), cmp);
        for (auto& j : all) {
            if (unite(j[1], j[2])) {
                if (j[0] <= cur_x) {
                    ++cnt[i];
                    sum1[i] += j[0];
                } else {
                    sum2[i] += j[0];
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            pr[j] = j;
            sz[j] = 1;
        }
    }
    int q, ans = 0;
    for (int i = 0; i < k; ++i) {
        if (i < p) {
            q = qq[i];
        } else {
            q = (q * a + b) % c;
        }
        int num = upper_bound(all_x.begin(), all_x.end(), q) - all_x.begin() - 1;
        ans ^= (cnt[num] * q - sum1[num] + sum2[num] - (n - 1 - cnt[num]) * q);
    }
    return ans;
}

inline int solve2(int n, int m, int p, int k, int a, int b, int c, vector <array <int, 3>> all, vector <int> qq) {
    pr.assign(n, 0);
    sz.assign(n, 1);
    for (int i = 0; i < n; ++i) pr[i] = i;
    int q, ans = 0;
    for (int i = 0; i < k; ++i) {
        if (i < p) {
            q = qq[i];
        } else {
            q = (q * a + b) % c;
        }
        cur_x = q;
        sort(all.begin(), all.end(), cmp);
        int tmp = 0;
        for (auto j : all) {
            if (unite(j[1], j[2])) tmp += abs(cur_x - j[0]);
        }
        ans ^= tmp;
        for (int j = 0; j < n; ++j) {
            sz[j] = 1;
            pr[j] = j;
        }
    }
    return ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> all(m);
        for (int i = 0; i < m; ++i) {
            cin >> all[i][1] >> all[i][2] >> all[i][0];
            --all[i][1];
            --all[i][2];
        }
        int p, k, a, b, c;
        cin >> p >> k >> a >> b >> c;
        vector <int> qq(p);
        for (int i = 0; i < p; ++i) cin >> qq[i];
        cout << solve1(n, m, p, k, a, b, c, all, qq);
    } else {
        int t;
        cin >> t;
        while (t--) {
            int n = rand() % 3 + 2, m = n - 1 + rand() % 2;
            pr.assign(n, 0);
            sz.assign(n, 1);
            for (int i = 0; i < n; ++i) pr[i] = i;
            vector <array <int, 3>> all;
            for (int i = 0; i < m; ++i) {
                if (i < n - 1) {
                    int x = rand() % n, y = rand() % n;
                    while (!unite(x, y)) {
                        x = rand() % n;
                        y = rand() % n;
                    }
                    all.push_back({rand() % 5, x, y});
                } else {
                    int x = rand() % n, y = rand() % n;
                    while (x == y) {
                        x = rand() % n;
                        y = rand() % n;
                    }
                    all.push_back({rand() % 5, x, y});
                }
            }
            int p = rand() % 5 + 1, k = p, a = 0, b = 0, c = 0;
            vector <int> qq(p);
            for (int i = 0; i < p; ++i) qq[i] = rand() % 10;
            if (solve1(n, m, p, k, a, b, c, all, qq) != solve2(n, m, p, k, a, b, c, all, qq)) {
                cout << n << " " << m << "\n";
                for (auto i : all) cout << i[1] + 1 << " " << i[2] + 1 << " " << i[0] << "\n";
                cout << p << " " << k << " " << a << " " << b << " " << c << "\n";
                for (int i = 0; i < p; ++i) cout << qq[i] << " ";
                return 0;
            }
        }
    }
}

/*
5 5
2 5 0
4 2 0
2 1 0
3 4 8
3 4 0
5 5 0 0 0
15 17 11 10 6
 */