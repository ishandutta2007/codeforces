#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
using namespace std;

const int INF = 1e9 + 15;
const int mod = 1000000007;

char mat[505][505];
int s_partvert[505][505];
int s_parthor[505][505];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i) {
        cin.get();
        cin.get(mat[i] + 1, 505);
    }

    int j;
    for (int i = 1; i <= n; ++ i)
        for (j = 1; j <= m; ++ j) {
            s_partvert[i][j] = s_partvert[i - 1][j] + s_partvert[i][j - 1] - s_partvert[i - 1][j - 1];
            s_parthor[i][j] = s_parthor[i - 1][j] + s_parthor[i][j - 1] - s_parthor[i - 1][j - 1];
            if (mat[i][j] == '.') {
                s_partvert[i][j] += (mat[i - 1][j] == '.');
                s_parthor[i][j] += (mat[i][j - 1] == '.');
            }
        }

    int q = 0;
    cin >> q;

    int lin1, col1, lin2, col2;
    int ans = 0;
    while (q --) {
        cin >> lin1 >> col1 >> lin2 >> col2;

        ans = 0;
        if (lin2 - lin1 >= 1) {
            ++ lin1;
            ans += s_partvert[lin2][col2] - s_partvert[lin2][col1 - 1] - s_partvert[lin1 - 1][col2] + s_partvert[lin1 - 1][col1 - 1];
            -- lin1;
        }

        if (col2 - col1 >= 1) {
            ++ col1;
            ans += s_parthor[lin2][col2] - s_parthor[lin2][col1 - 1] - s_parthor[lin1 - 1][col2] + s_parthor[lin1 - 1][col1 - 1];
            -- col1;
        }

        cout << ans << '\n';
    }

    return 0;
}