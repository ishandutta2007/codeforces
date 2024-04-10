#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 2005;
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

char A[Nmax][Nmax];
bool used[Nmax][Nmax];

bool good(int x, int y) {
    if (A[x][y] != '*') return 0;

    if (A[x - 1][y] == '.' && A[x - 1][y + 1] == '.' && A[x][y + 1] == '.') return true;
    if (A[x][y + 1] == '.' && A[x + 1][y + 1] == '.' && A[x + 1][y] == '.') return true;
    if (A[x + 1][y] == '.' && A[x + 1][y - 1] == '.' && A[x][y - 1] == '.') return true;
    if (A[x][y - 1] == '.' && A[x - 1][y - 1] == '.' && A[x - 1][y] == '.') return true;
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i)
        cin >> (A[i] + 1);

    queue<pair<int, int>> Q;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (A[i][j] == '.') {
                Q.push({i, j});
                used[i][j] = true;
            }
        }
    }

    while (!Q.empty()) {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();

        A[x][y] = '.';
        for (int k = 0; k < 8; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (good(nx, ny) && !used[nx][ny]) {
                used[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }

    for (int i = 1; i <= N; ++i)
        cout << (A[i] + 1) << '\n';
}