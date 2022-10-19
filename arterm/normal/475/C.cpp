#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define M 1010

int n, m;
char s[M][M], f[M][M];

void read() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> s[i][j];
}

void rev() {
    swap(n, m);
    for (int i = 0; i < M; ++i)
        for (int j = i; j < M; ++j) {
            swap(s[i][j], s[j][i]);
        }
}

void ini() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            f[i][j] = '.';
}

void brush(int sx, int tx, int sy, int ty) {
    for (int i = sx; i < tx; ++i)
        for (int j = sy; j < ty; ++j)
            f[i][j] = 'X';
}

int kill() {
    int si, sj;
    bool found = false;
    for (int i = 1; i <= n && !found; ++i)
        for (int j = 1; j <= m && !found; ++j)
            if (s[i][j] == 'X') {
                si = i;
                sj = j;
                found = true;
            }

    int lx = 0;
    int ly = 0;
    while (s[si][sj + ly] == 'X')
        ++ly;
    while (s[si + lx][sj] == 'X')
        ++lx;
    bool down = true;

    ini();

    //cout << si << " " << sj << " :s\n" << lx << " " << ly << ":l\n";

    while (true) {
        if (s[si][sj + ly] == 'X') {
            down = false;
            brush(si, si + lx, sj, sj + 1);
            ++sj;
            continue;
        }
        if (down) {
            if (lx > 1) {
                brush(si, si + 1, sj, sj + ly);
                ++si;
                --lx;
                continue;
            }
            break;
        }
        if (s[si + lx][sj] == 'X') {
            brush(si, si + 1, sj, sj + ly);
            ++si;
            continue;
        }
        break;
    }

    brush(si, si + lx, sj, sj + ly);

    /*for (int i = 1; i <= n; ++i, cout << "\n")
        for (int j = 1; j <= m; ++j)
            cout << f[i][j];
    cout << "--\n";*/

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (f[i][j] != s[i][j])
                return n * m + 1;
    return lx * ly;
}



int main() {
#ifdef TURTLE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    read();
    int ans = n * m + 1;
    ans = min(ans, kill());
    rev();
    ans = min(ans, kill());

    if (ans == n * m + 1)
        cout << "-1\n";
    else
        cout << ans << "\n";


    return 0;
}