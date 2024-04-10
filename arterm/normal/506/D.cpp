#include <bits/stdc++.h>

using namespace std;

#define M 100100
#define B 256

int n, m, l[M], lc = 0;
vector<pair<int, int>> e[M];
bool used[M];

vector<int> big[M];
int bigc = 0;

pair<int, int> p[M * B];
int pc = 0;

void read() {
    cin >> n >> m;
    for (int i = 0, x, y, c; i < m; ++i) {
        cin >> x >> y >> c;
        e[c].push_back(make_pair(x, y));
        e[c].push_back(make_pair(y, x));
    }

    for (int i = 1; i <= m; ++i)
        sort(e[i].begin(), e[i].end());
}

void dfs(int v, int c) {
    used[v] = true;
    l[lc++] = v;
    int l = lower_bound(e[c].begin(), e[c].end(), make_pair(v, 0)) - e[c].begin();
    int r = lower_bound(e[c].begin(), e[c].end(), make_pair(v + 1, 0)) - e[c].begin();
    for (int i = l; i < r; ++i) {
        int to = e[c][i].second;
        if (!used[to])
            dfs(to, c);
    }
}

void addBig() {
    sort(l, l + lc);
    big[bigc] = vector<int>(l, l + lc);
    ++bigc;
}

void addSmall() {
    for (int i = 0; i < lc; ++i)
        for (int j = i + 1; j < lc; ++j) {
            int x = l[i];
            int y = l[j];
            if (x > y)
                swap(x, y);
            p[pc++] = make_pair(x, y);
        }
}

void build() {
    for (int i = 1; i <= m; ++i) {

        for (auto x : e[i])
            if (!used[x.first]) {
                dfs(x.first, i);
                if (lc >= B) {
                    addBig();
                } else {
                    addSmall();
                }
                lc = 0;
            }

        for (auto x : e[i])
            used[x.first] = false;
    }

    sort(p, p + pc);
}

void kill() {
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        int ans = 0;
        ans += upper_bound(p, p + pc, make_pair(x, y)) - lower_bound(p, p + pc, make_pair(x, y));
        for (int i = 0; i < bigc; ++i)
            if (binary_search(big[i].begin(), big[i].end(), x) 
                && binary_search(big[i].begin(), big[i].end(), y))
                ans++;

        cout << ans << "\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    build();
    kill();
    return 0;
}