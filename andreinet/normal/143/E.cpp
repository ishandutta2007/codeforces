#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long i64;

const int Nmax = 13;
const int dx[4][5] = {{-2, -1, 0, 0, 0}, {-1, 0, 0, 0, 1}, {0, 0, 0, 1, 2 }, {-1, 0, 0, 0, 1 }};
const int dy[4][5] = {{0, 0, -1, 0, 1 }, {0, 0, 1, 2, 0 }, {-1, 0, 1, 0, 0}, {0, -2, -1, 0, 0}};

char A[Nmax][Nmax];
char Ans[Nmax][Nmax];

int N, M;

int cnt = 0, ans = -1;
bool goodPos(int x, int y, int k) {
    for (int l = 0; l < 5; ++l) {
        int nx = x + dx[k][l], ny = y + dy[k][l];
        if (nx < 1 || nx > N || ny < 1 || ny > M) return false;
        if (A[nx][ny] != '.') return false;
    }
    return true;
}

void filll(int x, int y, int k) {
    for (int l = 0; l < 5; ++l) {
        int nx = x + dx[k][l], ny = y + dy[k][l];
        A[nx][ny] = 'A' + cnt;
    }
}


void unfill(int x, int y, int k) {
    for (int l = 0; l < 5; ++l) {
        int nx = x + dx[k][l], ny = y + dy[k][l];
        A[nx][ny] = '.';
    }
}

void back(int x, int y) {
    if (y > M) {
        x = x + 1;
        y = 1;
    }
    if (x > N) {
        if (cnt > ans) {
            ans = cnt;
            memcpy(Ans, A, sizeof Ans);
        }
        return;
    }
    if (cnt + ((N - x) * M + M - y) / 5 < ans) return;
    if (A[x][y] != '.') {
        back(x, y + 1);
        return;
    }
    for (int k = 0; k < 4; ++k) {
        if (goodPos(x, y, k)) {
            filll(x, y, k);
            cnt++;
            if (k == 1) back(x, y + 3);
            else back(x, y + 1);
            unfill(x, y, k);
            cnt--;
        }
    }
    back(x, y + 1);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            A[i][j] = '.';
    back(1, 1);
    cout << ans << '\n';
    for (int i = 1; i <= N; ++i)
        cout << (Ans[i] + 1) << '\n';
}