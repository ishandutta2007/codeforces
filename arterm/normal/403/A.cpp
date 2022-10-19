#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 70

bool u[M][M];

void kill(int n, int p){
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
        u[i][j] = 0;

    for (int i = 1; i <= n; ++i)
        u[i][i] = 1;

    for (int i = 1; i <= n; ++i){
        int x = i % n + 1;
        int y = (i + 1) % n + 1;
        cout << i << " " << x << "\n";
        cout << i << " " << y << "\n";
        u[i][x] = u[x][i] = 1;
        u[i][y] = u[y][i] = 1;
    }

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    if (!u[i][j] && p > 0){
        --p;
        cout << i << " " << j << "\n";
        u[i][j] = u[j][i] = 1;
    }
}

int main(){
#ifdef HINDI
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif
    int t, n, p;
    cin >> t;
    while (t--){
        cin >> n >> p;
        kill(n, p);
    }
    return 0;
}