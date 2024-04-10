#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define M 100100

int n, a[M], x, y;
int t[2][M];
map<int, int> num;
bool u[M], col[M];

void read() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        num[a[i]] = i;
    }
}

void dfs(int v, int color) {
    u[v] = true;
    col[v] = color;
    for (int i = 0; i < 2; ++i)
        if (!u[t[i][v]] && t[i][v] != 0)
            dfs(t[i][v], color);
}

void kill() {
    if (x == y) {
        for (int i = 1; i <= n; ++i)
            if (num[x - a[i]] == 0) {
                cout << "NO\n";
                return;
            }

        cout << "YES\n";
        for (int i = 1; i <= n; ++i, cout << " ")
            cout << 0;
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        t[0][i] = num[x - a[i]];
        t[1][i] = num[y - a[i]];
        if (t[0][i] == 0 && t[1][i] == 0) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 1; i <= n; ++i)
        if (!u[i])
            if (t[0][i] == 0 || t[1][i] == 0) {
                int color = 0;
                if (t[0][i] == 0)
                    color = 1;
                dfs(i, color);
            }

    for (int i = 1; i <= n; ++i)
        if (t[col[i]][i] != 0 && col[t[col[i]][i]] == col[i]) {
            //
        }
        else {
            cout << "NO\n";
            return;
        }

    cout << "YES\n";
    for (int i = 1; i <= n; ++i, cout << " ")
        cout << col[i];
}


int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    read();
    kill();

    return 0;
}