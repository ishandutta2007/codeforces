#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000 + 5;

int N, M;
string mat[NMAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dist[NMAX][NMAX];

int main()
{
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= N; ++ i) {
        cin >> mat[i];
        mat[i] = " " + mat[i];
    }

    pair <int, int> where;
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= M; ++ j)
            if (mat[i][j] == 'E')
                where = {i, j};

    queue <pair <int, int> > q;
    q.push(where);
    dist[where.first][where.second] = 1;

    while (!q.empty()) {
        const int l = q.front().first;
        const int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++ i) {
            const int nl = l + dx[i];
            const int nc = c + dy[i];
            if (nl >= 1 && nc >= 1 && nl <= N && nc <= M && !dist[nl][nc] && mat[nl][nc] != 'T') {
                dist[nl][nc] = 1 + dist[l][c];
                q.push({nl, nc});
            }
        }
    }

    int my_tmp = 0;
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= M; ++ j)
            if (mat[i][j] == 'S')
                my_tmp = dist[i][j] - 1;

    int ans = 0;
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= M; ++ j)
            if (isdigit(mat[i][j])) {
                int cnt = mat[i][j] - '0';
                -- dist[i][j];
                if (dist[i][j] != -1 && dist[i][j] <= my_tmp)
                    ans += cnt;
            }

    cout << ans << '\n';
    return 0;
}