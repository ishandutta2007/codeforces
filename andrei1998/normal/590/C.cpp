#include <iostream>
#include <cstring>
#include <deque>
#include <utility>

using namespace std;

int n, m;
char mat[1005][1005];

int dists1[1005][1005];
int dists2[1005][1005];
int dists3[1005][1005];

deque <pair <int, int> > coada;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void do_bfs (int dists[1005][1005]) {
    pair <int, int> y;
    int k, nx, ny;

    while (!coada.empty()) {
        y = coada.front();
        coada.pop_front();

        for (k = 0; k < 4; ++ k) {
            nx = y.first + dx[k];
            ny = y.second + dy[k];

            if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && !dists[nx][ny] && mat[nx][ny] != '#') {
                dists[nx][ny] = dists[y.first][y.second] + (mat[nx][ny] == '.');

                if (mat[nx][ny] == '.')
                    coada.push_back(make_pair(nx, ny));
                else
                    coada.push_front(make_pair(nx, ny));
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i) {
        cin.get();
        cin.get(mat[i] + 1, 1005);
    }

    int j;
    //BFS1

    for (int i = 1; i <= n; ++ i)
        for (j = 1; j <= m; ++ j)
            if (mat[i][j] == '1') {
                dists1[i][j] = 1;
                coada.push_back(make_pair(i, j));

             //   cout << "incep cu " << i << ' ' << j << endl;
            }

    do_bfs(dists1);


    //BFS2

    for (int i = 1; i <= n; ++ i)
        for (j = 1; j <= m; ++ j)
            if (mat[i][j] == '2') {
                dists2[i][j] = 1;
                coada.push_back(make_pair(i, j));
            }

    do_bfs(dists2);


    //BFS3

    for (int i = 1; i <= n; ++ i)
        for (j = 1; j <= m; ++ j)
            if (mat[i][j] == '3') {
                dists3[i][j] = 1;
                coada.push_back(make_pair(i, j));
            }

    do_bfs(dists3);

    const int inf = 1e9 + 5;
    int ans = inf;

    for (int i = 1; i <= n; ++ i)
        for (j = 1; j <= m; ++ j)
            //cout << i << ' ' << j << ' ' << dists1[i][j] + dists2[i][j] + dists3[i][j] - 2 * (mat[i][j] == '.') << endl;
            if (dists1[i][j] + dists2[i][j] + dists3[i][j] - 2 * (mat[i][j] == '.') < ans && dists1[i][j] && dists2[i][j] && dists3[i][j])
                ans = dists1[i][j] + dists2[i][j] + dists3[i][j] - 2 * (mat[i][j] == '.');
    if (ans == inf)
        cout << "-1\n";
    else
        cout << ans - 3 << '\n';
    return 0;
}