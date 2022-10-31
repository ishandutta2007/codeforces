#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 1005;
const int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};

bool used[Nmax][Nmax];
int N, M;

int cnt[2];

void dfs(int x, int y, int s) {
    cnt[s]++;
    used[x][y] = true;

    for (int k = 0; k < 8; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 1 || nx > N || ny < 1 || ny > M) continue;

        if (!used[nx][ny])
            dfs(nx, ny, s ^ 1);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    cin >> N >> M;

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (!used[i][j]) {
                cnt[0] = cnt[1] = 0;
                dfs(i, j, 0);
                ans += max(cnt[0], cnt[1]);
            }
        }
    }

    cout << ans << '\n';
}