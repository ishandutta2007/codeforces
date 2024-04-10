#include <iostream>
#include <bitset>

using namespace std;

const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

const int NMAX = 31;

int n;
int v[NMAX];

bitset <11 * NMAX> vis[11 * NMAX][9][NMAX][6];
bool viss[11 * NMAX][11 * NMAX];

int ans;
void rec(int x, int y, int dir, int who, int rem) {
    if (who == n + 1)
        return ;

    if (vis[y][dir][who][rem][x])
        return ;
    if (!viss[x][y]) {
        ++ ans;
        viss[x][y] = true;
    }
    vis[y][dir][who][rem][x] = 1;

    if (rem == 1) {
        //Complex
        int nDir = (dir + 8 - 1) % 8;
        rec(x + dx[nDir], y + dy[nDir], nDir, who + 1, v[who + 1]);

        nDir = (dir + 1) % 8;
        rec(x + dx[nDir], y + dy[nDir], nDir, who + 1, v[who + 1]);
    }
    else
        rec(x + dx[dir], y + dy[dir], dir, who, rem - 1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    rec(5 * 30 + 5, 5 * 30 + 5, 0, 1, v[1]);

    cout << ans << '\n';
    return 0;
}