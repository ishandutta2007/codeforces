#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 507;
const int MOD = 1'000'000'007;

int n, m;
char in[N][N];
char ans[N][N];

void connect(int ra, int rb)
{
    if (m == 1) {
        for (int row = ra + 1; row < rb; ++row) {
            ans[row][1] = 'X';
        }
    } else {
        int col = 1;
        for (int r = ra + 1; r < rb; ++r) {
            for (int c = 1; c <= 2; ++c) {
                if (ans[r][c] == 'X') {
                    col = c;
                }
            }
        }

        ans[ra + 1][col] = ans[ra + 2][col] = 'X';
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", in[i] + 1);
            for (int j = 1; j <= m; ++j) {
                ans[i][j] = in[i][j];
            }
        }

        vector <int> full_rows;
        if (n % 3 == 1) {
            for (int r = 1; r <= n; r += 3) {
                full_rows.push_back(r);
            }
        } else {
            for (int r = 2; r <= n; r += 3) {
                full_rows.push_back(r);
            }
        }

        for (auto row: full_rows) {
            for (int col = 1; col <= m; ++col) {
                ans[row][col] = 'X';
            }
        }

        for (int i = 1; i < (int)full_rows.size(); ++i) {
            connect(full_rows[i - 1], full_rows[i]);
        }

        for (int row = 1; row <= n; ++row) {
            for (int col = 1; col <= m; ++col) {
                printf("%c", ans[row][col]);
            }

            puts("");
        }
    }

    return 0;
}