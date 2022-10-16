#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

const int NMAX = 250 + 5;

int N, M, q, p;
string mat[NMAX];

int last[NMAX][NMAX];
int dist[NMAX][NMAX];

lint sum[NMAX][NMAX];
int anss;
bool done[NMAX][NMAX];

int tmp;
void bfs(int l, int c, int st) {
    queue <pair <int, int> > q;
    ++ tmp;

    q.push({l, c});
    last[l][c] = tmp;
    dist[l][c] = st;

    if (!done[l][c]) {
        sum[l][c] += dist[l][c];
        if (sum[l][c] > p) {
            ++ anss;
            done[l][c] = true;
        }
    }

    while (!q.empty()) {
        pair <int, int> node = q.front();
        q.pop();
        if (dist[node.first][node.second] == 0)
            continue;

        for (auto d: {make_pair(1, 0), {-1, 0}, {0, 1}, {0, -1}}) {
            pair <int, int> nNode = {node.first + d.first, node.second + d.second};
            if (nNode.first >= 1 && nNode.second >= 1 && nNode.first <= N && nNode.second <= M && last[nNode.first][nNode.second] < tmp && mat[nNode.first][nNode.second] != '*') {
                last[nNode.first][nNode.second] = tmp;
                dist[nNode.first][nNode.second] = dist[node.first][node.second] / 2;
                if (!done[nNode.first][nNode.second]) {
                    sum[nNode.first][nNode.second] += dist[nNode.first][nNode.second];
                    if (sum[nNode.first][nNode.second] > p) {
                        ++ anss;
                        done[nNode.first][nNode.second] = true;
                    }
                }
                q.push(nNode);
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> q >> p;

    for (int i = 1; i <= N; ++ i) {
        cin >> mat[i];
        mat[i] = " " + mat[i];
    }

    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= M; ++ j)
            if (isalpha(mat[i][j]))
                bfs(i, j, q * (mat[i][j] - 'A' + 1));

    cout << anss << '\n';
    return 0;
}