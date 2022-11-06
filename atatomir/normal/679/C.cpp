#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 555

int defX[4] = {-1, 1, 0, 0};
int defY[4] = {0, 0, -1, 1};

int n, k, i, j, t, how, l1, l2, c1, c2;
char mat[maxN][maxN];
int sums[maxN][maxN];
int belong[maxN][maxN];
int cnt[maxN * maxN];

queue< pair<int, int> > Q;
vector<int> event[maxN];

int act[maxN * maxN];
int total;

int best;


void bfs(int x, int y) {

    belong[x][y] = how;
    Q.push(mp(x, y));

    while (!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        cnt[how]++;

        for (int i = 0; i < 4; i++) {
            int xx = x + defX[i];
            int yy = y + defY[i];

            if (mat[xx][yy] == 'X' || belong[xx][yy] != 0) continue;
            belong[xx][yy] = how;
            Q.push(mp(xx, yy));
        }
    }
}

int grid_sum(int l1, int c1, int l2, int c2) {
    return sums[l2][c2] - sums[l1 - 1][c2] - sums[l2][c1 - 1] + sums[l1 - 1][c1 - 1];
}

void add_line(int ln) {
    int i, j, limit, l, r;

    limit = min(n, ln + k);

    for (i = max(1, ln - 1); i <= limit; i++) {
        for (j = 1; j <= n; j++) {
            if (mat[i][j] == 'X') continue;

            l = max(1, j - k);
            r = min(n, j + 1);

            if (i == ln - 1 || i == ln + k) {
                l = max(1, j - k + 1);
                r = min(n, j + 1 - 1);
            }

            event[l].pb(+belong[i][j]);
            event[r + 1].pb(-belong[i][j]);
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%s\n", mat[i] + 1);
        for (j = 1; j <= n; j++) {
            sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            if (mat[i][j] == '.') sums[i][j]++;
        }
    }

    for (i = 0; i <= n + 1; i++)
        mat[0][i] = mat[n + 1][i] = mat[i][0] = mat[i][n + 1] = 'X';

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (mat[i][j] == 'X') continue;
            if (belong[i][j] != 0) continue;

            how++;
            bfs(i, j);
        }
    }

    event[1].reserve(n * n + 3);
    for (i = 2; i <= n + 1; i++) event[i].reserve(n + 3);

    for (i = 1; i <= n; i++) {
        add_line(i);

        for (j = 1; j <= n + 1; j++) {
            for (auto e : event[j]) {
                if (e > 0) {
                    if (++act[e] == 1) total += cnt[e];
                } else {
                    if (--act[-e] == 0) total -= cnt[-e];
                }
            }

            event[j].clear();

            if (i + k - 1 <= n && j + k - 1 <= n)
                best = max(best, total + k * k - grid_sum(i, j, i + k - 1, j + k - 1));
        }
    }

    printf("%d", best);

    return 0;
}