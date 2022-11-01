#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 505, MMAX = NMAX * NMAX;

char A[NMAX][NMAX];
bool used[NMAX][NMAX];
int compInd[NMAX][NMAX];
int compSize[MMAX];
int compXmin[MMAX], compXmax[MMAX];
int compYmin[MMAX], compYmax[MMAX];
int comps;

int compAdd[2 * NMAX][2 * NMAX];
int sums[NMAX][NMAX];
bool usedComp[MMAX];

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    used[x][y] = true;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        compInd[x][y] = comps;

        compXmin[comps] = min(compXmin[comps], x);
        compXmax[comps] = max(compXmax[comps], x);
        compYmin[comps] = min(compYmin[comps], y);
        compYmax[comps] = max(compYmax[comps], y);
        compSize[comps]++;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!used[nx][ny] && A[nx][ny] == '.') {
                used[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i] + 1;
    }
    memset(compInd, -1, sizeof compInd);
    memset(compXmin, 0x3f, sizeof compXmin);
    memset(compYmin, 0x3f, sizeof compYmin);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i][j] == '.' && !used[i][j]) {
                bfs(i, j);
                int xmin = compXmin[comps];
                int xmax = compXmax[comps];
                int ymin = compYmin[comps];
                int ymax = compYmax[comps];
                int size = compSize[comps];
                if (xmax - xmin + 1 <= k &&
                    ymax - ymin + 1 <= k) {
                    compAdd[xmax][ymax] += size;
                    compAdd[xmin + k][ymax] -= size;
                    compAdd[xmax][ymin + k] -= size;
                    compAdd[xmin + k][ymin + k] += size;
                }
                comps++;
            }
            sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            if (A[i][j] == 'X') {
                sums[i][j]++;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            compAdd[i][j] += compAdd[i - 1][j] + compAdd[i][j - 1] -
                             compAdd[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= n; ++j) {
            int sum = sums[i][j] - sums[i - k][j] - sums[i][j - k] +
                      sums[i - k][j - k];
            for (int l = j - k + 1; l <= j; ++l) {
                int x = compInd[i - k][l];
                if (x != -1 && !usedComp[x]) {
                    usedComp[x] = true;
                    sum += compSize[x];
                }
                x = compInd[i + 1][l];
                if (x != -1 && !usedComp[x]) {
                    usedComp[x] = true;
                    sum += compSize[x];
                }
            }
            for (int l = i - k + 1; l <= i; ++l) {
                int x = compInd[l][j - k];
                if (x != -1 && !usedComp[x]) {
                    usedComp[x] = true;
                    sum += compSize[x];
                }
                x = compInd[l][j + 1];
                if (x != -1 && !usedComp[x]) {
                    usedComp[x] = true;
                    sum += compSize[x];
                }
            }
            sum += compAdd[i][j];
            ans = max(ans, sum);
            for (int l = j - k + 1; l <= j; ++l) {
                int x = compInd[i - k][l];
                usedComp[x] = false;
                x = compInd[i + 1][l];
                usedComp[x] = false;
            }
            for (int l = i - k + 1; l <= i; ++l) {
                int x = compInd[l][j - k];
                usedComp[x] = false;
                x = compInd[l][j + 1];
                usedComp[x] = false;
            }
        }
    }
    cout << ans << '\n';
}