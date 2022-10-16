#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

int n;
char mat[55][55];

int c = 0;
inline void get_c () {
    int j;
    for (int i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            c += mat[i][j] == 'x';
}

bool vis[55][55];

inline bool works (int dx, int dy) {
    int j;
    for (int i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (mat[i][j] == 'o' && i + dx >= 1 && j + dy >= 1 && i + dx  <= n && j + dy  <= n && mat[i + dx][j + dy] == '.')
                return false;

    for (int i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (mat[i][j] == 'o' && i + dx >= 1 && j + dy >= 1 && i + dx  <= n && j + dy  <= n && mat[i + dx][j + dy] == 'x') {
                c -= !vis[i + dx][j + dy];
                vis[i + dx][j + dy] = true;
            }

    return true;
}

char anss[105][105];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin.get();
        cin.get(mat[i] + 1, 55);
    }
    get_c();

    vector <pair <int, int> > ans;

    int j;
    for (int i = - n + 1; i < n; i++)
        for (j = - n + 1; j < n; j++)
            if ((i != 0 || j != 0) && works(i, j))
                ans.push_back(make_pair(i, j));

    if (c) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for (int i = 1; i <= 2 * n - 1; i++) {
        for (j = 1; j <= 2 * n - 1; j++)
            anss[i][j] = '.';
        anss[i][2 * n] = '\0';
    }

    anss[n][n] = 'o';

    for (auto it: ans)
        anss[n + it.first][n + it.second] = 'x';

    for (int i = 1; i <= 2 * n - 1; i++)
        cout << anss[i] + 1 << '\n';
    return 0;
}