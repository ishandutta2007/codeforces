#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1e9 + 7;
int ans = 0;
bool kek[10][10][10][10];
bool c[10][10];
int k;
vector <int> cur;

inline bool check() {
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
            if (kek[i + 1][cur[i]][j + 1][cur[j]]) return false;
        }
    }
    return true;
}

void gen() {
    if (cur.size() == k) {
        ans += check();
        return;
    }
    for (int i = 0; i <= cur.size(); ++i) {
        if (c[cur.size() + 1][i]) continue;
        cur.push_back(i);
        gen();
        cur.pop_back();
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
        const int len = 2e5 + 1;
        int n, m;
        cin >> n >> m >> k;
        vector <vector <pair <int, int>>> a(n);
        for (int i = 0; i < m; ++i) {
            int x, y, w;
            cin >> x >> y >> w;
            x--; y--;
            a[x].emplace_back(w, y);
        }
        for (int i = 0; i < n; ++i) {
            sort(a[i].begin(), a[i].end());
        }
        vector <vector <bitset <len>>> b(10, vector <bitset <len>> (10));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < a[i].size(); ++j) {
                if (b[a[i].size()][j][a[i][j].second]) {
                    c[a[i].size()][j] = true;
                }
                else {
                    b[a[i].size()][j].set(a[i][j].second);
                }
            }
        }
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int ii = 1; ii <= k; ++ii) {
                    for (int jj = 0; jj < ii; ++jj) {
                        if ((b[i][j] & b[ii][jj]) == 0) {

                        }
                        else {
                            kek[i][j][ii][jj] = true;
                        }
                    }
                }
            }
        }
        gen();
        cout << ans;
    }
    else {
        int t;
        cin >> t;
        while (t--) {
            if (t % 100 == 0) cout << t << "\n";

        }
    }
}