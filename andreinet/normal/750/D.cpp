#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int MMAX = 311;
const int NMAX = 35;

int row[MMAX][MMAX];
int col[MMAX][MMAX];
int diag1[MMAX][MMAX];
int diag2[MMAX][MMAX];

bool dp[MMAX][MMAX][8];

struct State {
    int x, y, n, dir;
};

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void mark(int x, int y, int nx, int ny) {
    if (x == nx) {
        row[x][min(y, ny)]++;
        row[x][max(y, ny) + 1]--;
    } else if (y == ny) {
        col[min(x, nx)][y]++;
        col[max(x, nx) + 1][y]--;
    } else {
        if (x > nx) {
            swap(x, nx);
            swap(y, ny);
        }
        if (y < ny) {
            diag1[x][y]++;
            diag1[nx + 1][ny + 1]--;
        } else {
            diag2[x][y]++;
            diag2[nx + 1][ny - 1]--;
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
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    A[1]--;

    queue<State> q;
    q.push({152, 152, 1, 0});
    row[152][152]++;
    row[152][153]--;
    int last = 1;
    while (!q.empty()) {
        State s = q.front();
        q.pop();

        if (s.n != last) {
            memset(dp, 0, sizeof dp);
        }

        int nx = s.x + dx[s.dir] * A[s.n];
        int ny = s.y + dy[s.dir] * A[s.n];
        int ndir1 = (s.dir + 7) % 8;
        int ndir2 = (s.dir + 1) % 8;
        if (!dp[nx][ny][ndir1]) {
            dp[nx][ny][ndir1] = true;
            if (s.n + 1 <= n) {
                q.push({nx, ny, s.n + 1, ndir1});
            }
        }
        if (!dp[nx][ny][ndir2]) {
            dp[nx][ny][ndir2] = true;
            if (s.n + 1 <= n) {
                q.push({nx, ny, s.n + 1, ndir2});
            }
        }
        mark(s.x, s.y, nx, ny);
        last = s.n;
    }
    for (int i = 1; i <= 303; ++i) {
        for (int j = 1; j <= 303; ++j) {
            row[i][j] += row[i][j - 1];
            col[i][j] += col[i - 1][j];
            diag1[i][j] += diag1[i - 1][j - 1];
        }
        for (int j = 303; j > 0; --j) {
            diag2[i][j] += diag2[i - 1][j + 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= 303; ++i) {
        for (int j = 1; j <= 303; ++j) {
            bool x = row[i][j] || col[i][j] || diag1[i][j] || diag2[i][j];
            ans += x;
        }
    }
    cout << ans << '\n';
}