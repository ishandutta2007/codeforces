#include <bits/stdc++.h>

using namespace std;

const int N = 101;
const int MOD = 1'000'000'007;

int n, m;
char in[N][N];

bool check_row(int r, char goal = 'A')
{
    for (int c = 1; c <= m; ++c) {
        if (in[r][c] != goal) {
            return false;
        }
    }

    return true;
}

bool check_col(int c, char goal = 'A')
{
    for (int r = 1; r <= n; ++r) {
        if (in[r][c] != goal) {
            return false;
        }
    }

    return true;
}

void solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", in[i] + 1);
    }

    bool is_a = false, is_p = false;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            is_a |= in[i][j] == 'A';
            is_p |= in[i][j] == 'P';
        }
    }

    if (!is_a) {
        puts("MORTAL");
        return;
    }

    if (!is_p) {
        puts("0");
        return;
    }

    if (n == 1) {
        if (in[1][1] == 'A' || in[1][m] == 'A') {
            puts("1");
        } else {
            puts("2");
        }

        return;
    }

    if (m == 1) {
        if (in[1][1] == 'A' || in[n][1] == 'A') {
            puts("1");
        } else {
            puts("2");
        }

        return;
    }
    
    if (check_row(1) || check_row(n)) {
        puts("1");
        return;
    }

    if (check_col(1) || check_col(m)) {
        puts("1");
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (check_row(i)) {
            puts("2");
            return;
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (check_col(i)) {
            puts("2");
            return;
        }
    }

    if (in[1][1] == 'A' || in[1][m] == 'A' || in[n][1] == 'A' || in[n][m] == 'A') {
        puts("2");
        return;
    }

    if (!check_row(1, 'P') || !check_row(n, 'P')) {
        puts("3");
        return;
    }

    if (!check_col(1, 'P') || !check_col(m, 'P')) {
        puts("3");
        return;
    }

    puts("4");
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}