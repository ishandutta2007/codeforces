#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

struct comp {
    int x, y;
    int sz;
};

string a[55];

bool used[55][55];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, k;

int dfs(int i, int j) {
    used[i][j] = true;
    int sz = 1;
    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
        sz = -1;
    }
    for (int t = 0; t < 4; t++) {
        int x = i + dx[t];
        int y = j + dy[t];

        if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] != '.' || used[x][y]) {
            continue;
        }
        int r = dfs(x, y);
        if (r == -1 || sz == -1) {
            sz = -1;
        } else {
            sz += r;
        }
    }
    return sz;
}

void fill(int i, int j) {
    a[i][j] = '*';
    for (int t = 0; t < 4; t++) {
        int x = i + dx[t];
        int y = j + dy[t];

        if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] != '.') {
            continue;
        }

        fill(x, y);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    sci(n, m, k);

    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }

    vector<comp> cs;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] && a[i][j] == '.') {
                int sz = dfs(i, j);
                if (sz == -1) {
                    continue;
                }
                cs.push_back({i, j, sz});
            }
        }
    }

    sort(cs.begin(), cs.end(), [](const comp& a, const comp& b) { return a.sz < b.sz; });

    int cur = cs.size();
    int ans = 0;
    for (int i = 0; i < cur - k; i++) {
        ans += cs[i].sz;
        fill(cs[i].x, cs[i].y);
    }

    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }



    return 0;
}