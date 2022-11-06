#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 500011
#define mod 1000000007
#define ll long long
#define inf 1000000000000000000LL

int n, h, w, i, j, pos;
char moves[maxN];

int x_axis, y_axis;

int def = 500000;
int first_x[maxN << 1];
int first_y[maxN << 1];
int min_x, min_y, max_x, max_y;

ll col[maxN];
ll line[maxN];
ll sums[maxN];
ll ans;

void init() {
    int i;

    for (i = 1; i <= n; i++) {
        if (moves[i] == 'L') x_axis--;
        if (moves[i] == 'R') x_axis++;
        if (moves[i] == 'U') y_axis--;
        if (moves[i] == 'D') y_axis++;
    }

    if (x_axis < 0) {
        x_axis *= -1;
        for (i = 1; i <= n; i++) {
            if (moves[i] == 'L')
                moves[i] = 'R';
            else
            if (moves[i] == 'R')
                moves[i] = 'L';
        }
    }

    if (y_axis < 0) {
        y_axis *= -1;
        for (i = 1; i <= n; i++) {
            if (moves[i] == 'U')
                moves[i] = 'D';
            else
            if (moves[i] == 'D')
                moves[i] = 'U';
        }
    }
}

void compute_first() {
    int i;

    x_axis = y_axis = 0;
    for (i = 1; i <= n; i++) {
        if (moves[i] == 'L') {
            x_axis--;
            if (!first_x[def + x_axis])
                first_x[def + x_axis] = i;
        }
        if (moves[i] == 'R') {
            x_axis++;
            if (!first_x[def + x_axis])
                first_x[def + x_axis] = i;
        }
        if (moves[i] == 'U') {
            y_axis--;
            if (!first_y[def + y_axis])
                first_y[def + y_axis] = i;
        }
        if (moves[i] == 'D') {
            y_axis++;
            if (!first_y[def + y_axis])
                first_y[def + y_axis] = i;
        }

        min_x = min(min_x, x_axis);
        min_y = min(min_y, y_axis);
        max_x = max(max_x, x_axis);
        max_y = max(max_y, y_axis);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d\n%s", &n, &h, &w, moves + 1);
    init();
    compute_first();

    if (x_axis == y_axis && x_axis == 0) {
        int dim_x = max_x - min_x + 1;
        int dim_y = max_y - min_y + 1;

        if (w >= dim_x && h >= dim_y) {
            printf("-1");
            return 0;
        }
    }

    ll full, rem;

    //! solve for columns (x-axis)
    for (i = 1; i <= w; i++) col[i] = inf;

    for (i = 1; i <= w; i++) {
        int need = w - i + 1;

        if (first_x[def - i] != 0)
            col[i] = first_x[def - i];
        if (first_x[def + need])
            col[i] = min(col[i], 1LL * first_x[def + need]);

        if (x_axis == 0 || max_x >= need)
            continue;

        full = (need - max_x + (x_axis - 1)) / x_axis;
        rem  = need - full * x_axis;

        col[i] = min(col[i], full * n + 1LL * first_x[def + rem]);
    }

    //! solve for lines
    for (i = 1; i <= h; i++) line[i] = inf;

    for (i = 1; i <= h; i++) {
        int need = h - i + 1;

        if (first_y[def - i] != 0)
            line[i] = first_y[def - i];
        if (first_y[def + need])
            line[i] = min(line[i], 1LL * first_y[def + need]);

        if (y_axis == 0 || max_y >= need)
            continue;

        full = (need - max_y + (y_axis - 1)) / y_axis;
        rem  = need - full * y_axis;

        line[i] = min(line[i], full * n + 1LL * first_y[def + rem]);
    }

    //! combine results
    sort(col + 1, col + w + 1);
    sort(line + 1, line + h + 1);

    for (i = 1; i <= h; i++) {
        sums[i] = sums[i - 1] + line[i];
        sums[i] %= mod;
    }

    pos = 0;
    for (i = 1; i <= w; i++) {
        while (pos < h && col[i] >= line[pos + 1]) pos++;

        ans += sums[pos];
        ans += (1LL * (h - pos) * (col[i] % mod)) % mod;
        while (ans >= mod) ans -= mod;
    }

    printf("%I64d", ans);

    return 0;
}