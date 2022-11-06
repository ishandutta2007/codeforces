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
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool w[1111][1111][4][3];
int n, m;
string a[1111];

void dfs(int vx, int vy, int d, int c) {
    w[vx][vy][d][c] = true;
    if (a[vx][vy] == 'T') {
        cout << "YES";
        exit(0);
    }
    for (int i = 0; i < 4; i++) {
        int x = vx + dx[i];
        int y = vy + dy[i];
        int nc = i == d ? c : c + 1;
        if (x < 0 || x >= n || y < 0 || y >= m || nc > 2 || w[x][y][i][nc] || a[x][y] == '*') {
            continue;
        }
        dfs(x, y, i, nc);
    }
}

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sci(n, m);
    int sx = -1;
    int sy = -1;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    dfs(sx, sy, 0, 0);
    dfs(sx, sy, 1, 0);
    dfs(sx, sy, 2, 0);
    dfs(sx, sy, 3, 0);

    cout << "NO";

    return 0;
}