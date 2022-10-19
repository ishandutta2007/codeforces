#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 1010
#define long long long

int n, m;
int a[M][M];
long d[4][M][M];
int dx[] = { 1, -1, -1, 1 };
int dy[] = { 1, -1, 1, -1 };
int sx[4], sy[4];

void read(void){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
        cin >> a[i][j];

    sx[0] = 1;
    sy[0] = 1;

    sx[1] = n;
    sy[1] = m;
    
    sx[2] = n;
    sy[2] = 0;

    sx[3] = 0;
    sy[3] = m;
}

void rundin(int sx, int sy, int dx, int dy, int num){

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j){
        int x = sx + (i - 1)*dx;
        int y = sy + (j - 1)*dy;
        int cur = a[x][y];
        
        d[num][x][y] = max(d[num][x-dx][y], d[num][x][y - dy]) + cur;
    }

}

void kill(void){
    for (int i = 0; i < 4; ++i)
        rundin(sx[i], sy[i], dx[i], dy[i], i);

    long ans = 0;

    for (int i = 2; i < n; ++i)
    for (int j = 2; j < m; ++j){
        long x1 = d[0][i - dx[0]][j] + d[1][i - dx[1]][j] + d[2][i][j - dy[2]] + d[3][i][j - dy[3]];
        long x2 = d[0][i][j - dy[0]] + d[1][i][j - dy[1]] + d[2][i - dx[2]][j] + d[3][i - dx[3]][j];

        ans = max(ans, max(x1, x2));
    }

    cout << ans << "\n";
}

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif
    
    read();
    kill();

    return 0;
}