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

int b[2222][2222];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    scid(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = 1e9;
        }
    }
    queue< pair<int, int> > q;
    for (int i = 0; i < k; i++) {
        scid(x, y);
        --x; --y;
        b[x][y] = 0;
        q.push({x, y});
    }
    pair<int, int> ans;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        ans = v;
        for (int i = 0; i < 4; i++) {
            int x = v.first + dx[i];
            int y = v.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m) {
                continue;
            }
            if (b[x][y] > b[v.first][v.second] + 1) {
                b[x][y] = b[v.first][v.second] + 1;
                q.push({x, y});
            }
        }
    }

    cout << ans.first + 1 << " " << ans.second + 1;


    return 0;
}