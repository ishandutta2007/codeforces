#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define ll long long
#define y1 ngsdf
#define ld long double
#define sqr(a) ( (a) * (a) )
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const ld E = 1e-9;
const int MAX = 1e9;

int n, m;
char ar[500][500];
bool bol[500][500];
int x1, y1, x2, y2;

int X[4] = { 1, 0, -1, 0 }, Y[4] = { 0, -1, 0, 1 };

void bfs(int x, int y, bool bo = false) {
    bol[x][y] = true;
    if (x == x2 && y == y2 && !bo) {
        int a = 0;
        for (int i = 0; i < 4; i++) {
            int x3 = x + X[i], y3 = y + Y[i];
            if (x3 < 0 || y3 < 0 || x3 >= n || y3 >= m)
                continue;
            if (ar[x3][y3] == '.' || (x3 == x1 && y3 == y1))
                a++;
        }
        cout << (a > 1 || ar[x2][y2] == 'X' ? "YES" : "NO");
        exit(0);
    }
    for (int i = 0; i < 4; i++) {
        int x3 = x + X[i], y3 = y + Y[i];
        if (x3 < 0 || y3 < 0 || x3 >= n || y3 >= m)
            continue;
        if((!bol[x3][y3] && ar[x3][y3] == '.') || (y3 == y2 && x3 == x2))
            bfs(x3, y3);
    }
}

int main() {

    cin >> n >> m;
    ms(bol);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> ar[i][j];
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--,y2--;
    bfs(x1, y1, true);
    cout << "NO";

}